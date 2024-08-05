/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:36:38 by plang             #+#    #+#             */
/*   Updated: 2024/08/05 14:39:37 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	read_map(char *check, t_game *game, int fd)
{
	char	*two_d_array;
	char	*str;

	two_d_array = ft_calloc(1, sizeof(char));
	if (!two_d_array)
		return (ft_putstr_fd(CALLOC_FAIL, 2));
	two_d_array = ft_joinstr_freestr(two_d_array, check);
	free(check);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
		{
			free(str);
			break ;
		}
		check_real_hight(str, game, two_d_array);
		two_d_array = ft_joinstr_freestr(two_d_array, str);
		free(str);
	}
	game->map = ft_split(two_d_array, '\n');
	free(two_d_array);
	close(fd);
}

void	check_map_width(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] != '\0')
	{
		if (game->mapwidth != (int)ft_strlen(game->map[i]))
			invalid_map(INVALID_BORDERS, game);
		i++;
	}
}

void	check_map_borders(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] != '\0')
	{
		if ((game->map[i][0] != '1')
		|| (game->map[i][game->mapwidth - 1] != '1'))
			invalid_map(INVALID_MAP_STRUCTURE, game);
		i++;
	}
	i = 0;
	while (game->map[0][i] != '\0')
	{
		if ((game->map[0][i] != '1')
		|| (game->map[game->maphight - 1][i] != '1'))
			invalid_map(INVALID_MAP_STRUCTURE, game);
		i++;
	}
}

void	check_map_content(t_game *game)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	str = "01PEC";
	while (game->map[i] != '\0')
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (ft_find_char(str, game->map[i][j]))
				invalid_map(INVALID_MAP_CONTENT, game);
			j++;
		}
		i++;
	}
}

void	map_check(char *map_file, t_game *game)
{
	int		fd;
	char	*check;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		invalid_map(INVALID_ARGV, game);
	check = get_next_line(fd);
	if (!check)
		invalid_map(INVALID_MAP_FILE, game);
	game->maphight++;
	read_map(check, game, fd);
	game->mapwidth = ft_strlen(game->map[0]);
	check_map_width(game);
	check_map_borders(game);
	check_map_content(game);
	check_p_e_c(game);
}
