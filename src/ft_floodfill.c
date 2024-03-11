/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floodfill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:59:54 by plang             #+#    #+#             */
/*   Updated: 2024/03/06 10:46:55 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_p_position(t_game *game)
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
			{
				game->y_sp = i;
				game->x_sp = j;
			}
			j++;
		}
		i++;
	}
}

void	ft_floodfill(t_game *game)
{
	get_p_position(game);
	fill(game->map, game->y_sp, game->x_sp, game);
	if ((game->collectable_count != game->collectable)
		|| (game->exit_count != game->exit))
		invalid_map(INVALID_PATH, game);
	restore_map(game);
}

void	fill(char **map, int y_sp, int x_sp, t_game *game)
{
	if ((y_sp < 0) || (x_sp < 0) || (y_sp > game->maphight -1)
		|| (x_sp > game->mapwidth -1))
		return ;
	if ((map[y_sp][x_sp] == 'P') || (map[y_sp][x_sp] == 'E')
		|| (map[y_sp][x_sp] == '0') || (map[y_sp][x_sp] == 'C'))
	{
		if (map[y_sp][x_sp] == 'C')
		{
			map[y_sp][x_sp] = 'c';
			game->collectable++;
		}
		if (map[y_sp][x_sp] == 'E')
		{
			map[y_sp][x_sp] = 'e';
			game->exit++;
		}
		if (map[y_sp][x_sp] == '0')
			map[y_sp][x_sp] = 'x';
		if (map[y_sp][x_sp] == 'P')
			map[y_sp][x_sp] = 'p';
		fill(map, y_sp -1, x_sp, game);
		fill(map, y_sp +1, x_sp, game);
		fill(map, y_sp, x_sp -1, game);
		fill(map, y_sp, x_sp +1, game);
	}
}

void	restore_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != '\0')
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'p')
				game->map[i][j] = 'P';
			if (game->map[i][j] == 'e')
				game->map[i][j] = 'E';
			if (game->map[i][j] == 'c')
				game->map[i][j] = 'C';
			if (game->map[i][j] == 'x')
				game->map[i][j] = '0';
			j++;
		}
		i++;
	}
}
