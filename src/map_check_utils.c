/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:21:38 by plang             #+#    #+#             */
/*   Updated: 2024/08/05 14:39:37 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	argument_check(char *argv)
{
	int		len;
	char	*ber;
	char	*file;

	len = ft_strlen(argv);
	ber = ".ber";
	file = ft_strnstr(argv, ber, len);
	if ((file == NULL) || (argv[0] == '.') || ft_strncmp(file, ber, len))
	{
		ft_putstr_fd(NOT_DOT_BER, 2);
		exit(1);
	}
}

void	check_p_e_c(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != '\0')
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'E')
				game->exit_count++;
			if (game->map[i][j] == 'P')
				game->player_count++;
			if (game->map[i][j] == 'C')
				game->collectable_count++;
			j++;
		}
		i++;
	}
	if ((game->exit_count != 1) || (game->player_count != 1))
		invalid_map(INVALID_P_AND_E, game);
	if (game->collectable_count < 1)
		invalid_map(INVALID_COLLECTABLES, game);
}

int	ft_find_char(char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[j] != '\0')
		{
			if (str[j] == c)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	check_real_hight(char *str, t_game *game, char *two_d_array)
{
	if (str[0] == '1')
		game->maphight++;
	if (str[0] == '\n')
		map_file_error(str, two_d_array);
}
