/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:09:46 by plang             #+#    #+#             */
/*   Updated: 2024/08/05 14:39:37 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_texture(t_game *game)
{
	game->back_g_txt = mlx_load_png("./textures/background.png");
	game->wall_txt = mlx_load_png("./textures/walls.png");
	game->goal_txt = mlx_load_png("./textures/goal.png");
	game->p_front_txt = mlx_load_png("./textures/p_front.png");
	game->p_back_txt = mlx_load_png("./textures/p_back.png");
	game->p_left_txt = mlx_load_png("./textures/p_left.png");
	game->p_right_txt = mlx_load_png("./textures/p_right.png");
	game->ring_txt = mlx_load_png("./textures/Ring.png");
	if ((!game->back_g_txt) || (!game->wall_txt) || (!game->goal_txt)
		|| (!game->p_front_txt) || (!game->p_back_txt) || (!game->p_left_txt)
		|| (!game->p_right_txt))
		ft_free_mlx(game, 1);
}

void	get_image(t_game *game)
{
	int	i;

	i = 0;
	game->back_g = mlx_texture_to_image(game->mlx, game->back_g_txt);
	game->wall = mlx_texture_to_image(game->mlx, game->wall_txt);
	game->goal = mlx_texture_to_image(game->mlx, game->goal_txt);
	game->p_front = mlx_texture_to_image(game->mlx, game->p_front_txt);
	game->p_back = mlx_texture_to_image(game->mlx, game->p_back_txt);
	game->p_left = mlx_texture_to_image(game->mlx, game->p_left_txt);
	game->p_right = mlx_texture_to_image(game->mlx, game->p_right_txt);
	while (i < game->collectable)
	{
		game->tokens[i] = mlx_texture_to_image(game->mlx, game->ring_txt);
		if (!game->tokens[i])
			ft_free_mlx(game, 1);
		i++;
	}
	if ((!game->back_g) || (!game->wall) || (!game->goal)
		|| (!game->p_front) || (!game->p_back) || (!game->p_left)
		|| (!game->p_right))
		ft_free_mlx(game, 1);
}

void	resize_images(t_game *game)
{
	int	i;

	i = 0;
	if (!mlx_resize_image(game->back_g, game->sq_sz * game->mapwidth, \
	game->sq_sz * game->maphight))
		ft_free_mlx(game, 1);
	if (!mlx_resize_image(game->wall, game->sq_sz, game->sq_sz))
		ft_free_mlx(game, 1);
	if (!mlx_resize_image(game->goal, game->sq_sz, game->sq_sz))
		ft_free_mlx(game, 1);
	if (!mlx_resize_image(game->p_front, game->sq_sz, game->sq_sz))
		ft_free_mlx(game, 1);
	if (!mlx_resize_image(game->p_back, game->sq_sz, game->sq_sz))
		ft_free_mlx(game, 1);
	if (!mlx_resize_image(game->p_left, game->sq_sz, game->sq_sz))
		ft_free_mlx(game, 1);
	if (!mlx_resize_image(game->p_right, game->sq_sz, game->sq_sz))
		ft_free_mlx(game, 1);
	while (i < game->collectable)
	{
		if (!mlx_resize_image(game->tokens[i], game->sq_sz, game->sq_sz))
			ft_free_mlx(game, 1);
		i++;
	}
}

void	init_game(t_game *game)
{
	game->y_sz = HEIGHT / game->maphight;
	game->x_sz = WIDTH / game->mapwidth;
	if (game->y_sz > game->x_sz)
		game->sq_sz = game->x_sz;
	else
		game->sq_sz = game->y_sz;
	game->tokens = ft_calloc(game->collectable, sizeof(mlx_image_t *));
	if (!game->tokens)
		invalid_map(CALLOC_FAIL, game);
	game->mlx = mlx_init(game->sq_sz * game->mapwidth, \
	game->sq_sz * game->maphight, "Eye and the Ring Dude", false);
	if (!game->mlx)
		invalid_map(MLX_FAIL, game);
	get_texture(game);
	get_image(game);
	mlx_set_window_size(game->mlx, game->sq_sz * game->mapwidth, \
	game->sq_sz * game->maphight);
	resize_images(game);
	if (mlx_image_to_window(game->mlx, game->back_g, 0, 0) < 0)
		ft_free_mlx(game, 1);
	get_p_position(game);
	put_img_to_window(game);
	put_player(game);
	put_collectable_image(game);
}

void	put_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != '\0')
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'P')
				put_player_images(i, j, game);
			j++;
		}
		i++;
	}
}
