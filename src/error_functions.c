/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:03:09 by plang             #+#    #+#             */
/*   Updated: 2024/08/05 14:39:37 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	invalid_map(char *str, t_game *game)
{
	if (game->map != NULL)
		ft_free_split(game->map);
	ft_putstr_fd(str, 2);
	exit(1);
}

void	failed_to_open(char *str, char *two_d_array)
{
	free(two_d_array);
	ft_putstr_fd(str, 2);
	exit(1);
}

void	map_file_error(char *str, char *two_d_array)
{
	free(str);
	free(two_d_array);
	ft_putstr_fd(INVALID_MAP, 2);
	exit(1);
}

void	ft_free_mlx(t_game *game, int option)
{
	remove_textures(game);
	if (game->tokens)
		free(game->tokens);
	if (option == 1)
	{
		remove_images(game);
		ft_free_split(game->map);
		ft_putstr_fd(MLX_FAIL, 2);
		exit(1);
	}
}
