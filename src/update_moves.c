/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:20:28 by plang             #+#    #+#             */
/*   Updated: 2024/08/05 14:39:37 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	picking_up_collectable(t_game *game)
{
	int	i;

	i = 0;
	while (game->collectable)
	{
		if (game->tokens[i]->instances->x == game->sq_sz * game->x_sp
			&& game->tokens[i]->instances->y == game->sq_sz * game->y_sp)
		{
			game->collectable--;
			game->tokens[i]->instances->enabled = false;
			break ;
		}
		i++;
	}
}

void	update_left(t_game *game)
{
	game->p_left->instances->x -= game->sq_sz;
	game->p_front->instances->x -= game->sq_sz;
	game->p_right->instances->x -= game->sq_sz;
	game->p_back->instances->x -= game->sq_sz;
	game->p_left->instances->enabled = true;
	game->p_front->instances->enabled = false;
	game->p_right->instances->enabled = false;
	game->p_back->instances->enabled = false;
	if (game->map[game->y_sp][game->x_sp] == 'P')
		game->map[game->y_sp][game->x_sp] = '0';
	if (game->map[game->y_sp][game->x_sp] == 'C')
		game->map[game->y_sp][game->x_sp] = '0';
	game->x_sp -= 1;
}

void	update_down(t_game *game)
{
	game->p_left->instances->y += game->sq_sz;
	game->p_front->instances->y += game->sq_sz;
	game->p_right->instances->y += game->sq_sz;
	game->p_back->instances->y += game->sq_sz;
	game->p_left->instances->enabled = false;
	game->p_front->instances->enabled = true;
	game->p_right->instances->enabled = false;
	game->p_back->instances->enabled = false;
	if (game->map[game->y_sp][game->x_sp] == 'P')
		game->map[game->y_sp][game->x_sp] = '0';
	if (game->map[game->y_sp][game->x_sp] == 'C')
		game->map[game->y_sp][game->x_sp] = '0';
	game->y_sp += 1;
}

void	update_right(t_game *game)
{
	game->p_left->instances->x += game->sq_sz;
	game->p_front->instances->x += game->sq_sz;
	game->p_right->instances->x += game->sq_sz;
	game->p_back->instances->x += game->sq_sz;
	game->p_left->instances->enabled = false;
	game->p_front->instances->enabled = false;
	game->p_right->instances->enabled = true;
	game->p_back->instances->enabled = false;
	if (game->map[game->y_sp][game->x_sp] == 'P')
		game->map[game->y_sp][game->x_sp] = '0';
	if (game->map[game->y_sp][game->x_sp] == 'C')
		game->map[game->y_sp][game->x_sp] = '0';
	game->x_sp += 1;
}

void	update_up(t_game *game)
{
	game->p_left->instances->y -= game->sq_sz;
	game->p_front->instances->y -= game->sq_sz;
	game->p_right->instances->y -= game->sq_sz;
	game->p_back->instances->y -= game->sq_sz;
	game->p_left->instances->enabled = false;
	game->p_front->instances->enabled = false;
	game->p_right->instances->enabled = false;
	game->p_back->instances->enabled = true;
	if (game->map[game->y_sp][game->x_sp] == 'P')
		game->map[game->y_sp][game->x_sp] = '0';
	if (game->map[game->y_sp][game->x_sp] == 'C')
		game->map[game->y_sp][game->x_sp] = '0';
	game->y_sp -= 1;
}
