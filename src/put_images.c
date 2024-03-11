/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:10:35 by plang             #+#    #+#             */
/*   Updated: 2024/03/07 14:29:37 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_img_to_window(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != '\0')
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == '1')
				if (mlx_image_to_window(game->mlx, game->wall, \
				j * game->sq_sz, i * game->sq_sz) < 0)
					ft_free_mlx(game, 1);
			if (game->map[i][j] == 'E')
				if (mlx_image_to_window(game->mlx, game->goal, \
				j * game->sq_sz, i * game->sq_sz) < 0)
					ft_free_mlx(game, 1);
			j++;
		}
		i++;
	}
}

void	put_player_images(int i, int j, t_game *game)
{
	if (mlx_image_to_window(game->mlx, game->p_left, \
	j * game->sq_sz, i * game->sq_sz) < 0)
		ft_free_mlx(game, 1);
	if (mlx_image_to_window(game->mlx, game->p_back, \
	j * game->sq_sz, i * game->sq_sz) < 0)
		ft_free_mlx(game, 1);
	if (mlx_image_to_window(game->mlx, game->p_right, \
	j * game->sq_sz, i * game->sq_sz) < 0)
		ft_free_mlx(game, 1);
	if (mlx_image_to_window(game->mlx, game->p_front, \
	j * game->sq_sz, i * game->sq_sz) < 0)
		ft_free_mlx(game, 1);
	game->p_left->instances->enabled = false;
	game->p_front->instances->enabled = true;
	game->p_right->instances->enabled = false;
	game->p_back->instances->enabled = false;
}

void	put_collectable_image(t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (game->map[i] != '\0')
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'C')
				if (mlx_image_to_window(game->mlx, game->tokens[k++], \
				j * game->sq_sz, i * game->sq_sz) < 0)
					ft_free_mlx(game, 1);
			j++;
		}
		i++;
	}
}

void	remove_textures(t_game *game)
{
	if (game->wall_txt)
		mlx_delete_texture(game->wall_txt);
	if (game->back_g_txt)
		mlx_delete_texture(game->back_g_txt);
	if (game->goal_txt)
		mlx_delete_texture(game->goal_txt);
	if (game->p_front_txt)
		mlx_delete_texture(game->p_front_txt);
	if (game->p_back_txt)
		mlx_delete_texture(game->p_back_txt);
	if (game->p_left_txt)
		mlx_delete_texture(game->p_left_txt);
	if (game->p_right_txt)
		mlx_delete_texture(game->p_right_txt);
	if (game->ring_txt)
		mlx_delete_texture(game->ring_txt);
}

void	remove_images(t_game *game)
{
	int	i;

	i = 0;
	if (game->wall)
		mlx_delete_image(game->mlx, game->wall);
	if (game->back_g)
		mlx_delete_image(game->mlx, game->back_g);
	if (game->goal)
		mlx_delete_image(game->mlx, game->goal);
	if (game->p_front)
		mlx_delete_image(game->mlx, game->p_front);
	if (game->p_back)
		mlx_delete_image(game->mlx, game->p_back);
	if (game->p_left)
		mlx_delete_image(game->mlx, game->p_left);
	if (game->p_right)
		mlx_delete_image(game->mlx, game->p_right);
	if (game->tokens)
	{
		while (game->tokens[i])
		{
			mlx_delete_image(game->mlx, game->tokens[i]);
			i++;
		}
	}
}
