/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:06:19 by plang             #+#    #+#             */
/*   Updated: 2024/03/06 15:52:15 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	key_actions(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_left(game);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_down(game);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_right(game);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_up(game);
}

void	move_left(t_game *game)
{
	if (game->map[game->y_sp][game->x_sp - 1] == 'E' && game->collectable == 0)
	{
		game->exit_flag = 1;
		mlx_close_window(game->mlx);
	}
	if ((game->map[game->y_sp][game->x_sp - 1] == '0')
	|| (game->map[game->y_sp][game->x_sp - 1] == 'C')
	|| (game->map[game->y_sp][game->x_sp - 1] == 'P')
	|| (game->map[game->y_sp][game->x_sp - 1] == 'E'))
	{
		update_left(game);
		if (game->map[game->y_sp][game->x_sp] == 'C')
		{
			picking_up_collectable(game);
			game->steps++;
			ft_printf("Steps taken: %d\n", game->steps);
		}
		if ((game->map[game->y_sp][game->x_sp] == '0')
		|| (game->map[game->y_sp][game->x_sp] == 'P')
		|| (game->map[game->y_sp][game->x_sp] == 'E'))
		{
			game->steps++;
			ft_printf("Steps taken: %d\n", game->steps);
		}
	}
}

void	move_down(t_game *game)
{
	if (game->map[game->y_sp + 1][game->x_sp] == 'E' && game->collectable == 0)
	{
		game->exit_flag = 1;
		mlx_close_window(game->mlx);
	}
	if ((game->map[game->y_sp + 1][game->x_sp] == '0')
	|| (game->map[game->y_sp + 1][game->x_sp] == 'C')
	|| (game->map[game->y_sp + 1][game->x_sp] == 'P')
	|| (game->map[game->y_sp + 1][game->x_sp] == 'E'))
	{
		update_down(game);
		if (game->map[game->y_sp][game->x_sp] == 'C')
		{
			picking_up_collectable(game);
			game->steps++;
			ft_printf("Steps taken: %d\n", game->steps);
		}
		if ((game->map[game->y_sp][game->x_sp] == '0')
		|| (game->map[game->y_sp][game->x_sp] == 'P')
		|| (game->map[game->y_sp][game->x_sp] == 'E'))
		{
			game->steps++;
			ft_printf("Steps taken: %d\n", game->steps);
		}
	}
}

void	move_right(t_game *game)
{
	if (game->map[game->y_sp][game->x_sp + 1] == 'E' && game->collectable == 0)
	{
		game->exit_flag = 1;
		mlx_close_window(game->mlx);
	}
	if ((game->map[game->y_sp][game->x_sp + 1] == '0')
	|| (game->map[game->y_sp][game->x_sp + 1] == 'C')
	|| (game->map[game->y_sp][game->x_sp + 1] == 'P')
	|| (game->map[game->y_sp][game->x_sp + 1] == 'E'))
	{
		update_right(game);
		if (game->map[game->y_sp][game->x_sp] == 'C')
		{
			picking_up_collectable(game);
			game->steps++;
			ft_printf("Steps taken: %d\n", game->steps);
		}
		if ((game->map[game->y_sp][game->x_sp] == '0')
		|| (game->map[game->y_sp][game->x_sp] == 'P')
		|| (game->map[game->y_sp][game->x_sp] == 'E'))
		{
			game->steps++;
			ft_printf("Steps taken: %d\n", game->steps);
		}
	}
}

void	move_up(t_game *game)
{
	if (game->map[game->y_sp - 1][game->x_sp] == 'E' && game->collectable == 0)
	{
		game->exit_flag = 1;
		mlx_close_window(game->mlx);
	}
	if ((game->map[game->y_sp - 1][game->x_sp] == '0')
	|| (game->map[game->y_sp - 1][game->x_sp] == 'C')
	|| (game->map[game->y_sp - 1][game->x_sp] == 'P')
	|| (game->map[game->y_sp - 1][game->x_sp] == 'E'))
	{
		update_up(game);
		if (game->map[game->y_sp][game->x_sp] == 'C')
		{
			picking_up_collectable(game);
			game->steps++;
			ft_printf("Steps taken: %d\n", game->steps);
		}
		if ((game->map[game->y_sp][game->x_sp] == '0')
		|| (game->map[game->y_sp][game->x_sp] == 'P')
		|| (game->map[game->y_sp][game->x_sp] == 'E'))
		{
			game->steps++;
			ft_printf("Steps taken: %d\n", game->steps);
		}
	}
}
