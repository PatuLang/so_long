/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:45:55 by plang             #+#    #+#             */
/*   Updated: 2024/08/05 14:39:37 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_putstr_fd(INVALID_ARGV, 2);
		exit(1);
	}
	argument_check(argv[1]);
	ft_memset(&game, 0, sizeof(game));
	map_check(argv[1], &game);
	ft_floodfill(&game);
	init_game(&game);
	mlx_key_hook(game.mlx, &key_actions, &game);
	mlx_loop(game.mlx);
	ft_free_mlx(&game, 0);
	if (game.exit_flag == 1)
		ft_putstr_fd(WIN_MESSAGE, 1);
	ft_free_split(game.map);
	mlx_terminate(game.mlx);
	return (0);
}
