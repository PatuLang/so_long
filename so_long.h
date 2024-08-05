/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:46:17 by plang             #+#    #+#             */
/*   Updated: 2024/08/05 14:39:37 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* ************************************************************************** */
/*                                 Librarys                                   */
/* ************************************************************************** */

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <fcntl.h>

/* ************************************************************************** */
/*                                  Macros                                    */
/* ************************************************************************** */

# define WIDTH 1920
# define HEIGHT 1080
# define WIN_MESSAGE "You are the EYE now!"
# define MLX_FAIL "Error\nMLX failed"
# define CALLOC_FAIL "Error\nCalloc faield"
# define NOT_DOT_BER "Error\nThat's not a .ber file"
# define INVALID_ARGV "Error\nNah ah ahh, we need ONE existing .ber file"
# define INVALID_BORDERS "Error\nThe brick wall is incomplete"
# define INVALID_MAP_STRUCTURE "Error\nCheck North, West, South or East border"
# define INVALID_MAP_CONTENT "Error\nInvalid signs on the map"
# define INVALID_P_AND_E "Error\nPlayer and exit count is not one"
# define INVALID_COLLECTABLES "Error\nNot enough collectables on the map"
# define INVALID_MAP_FILE "Error\nThat is not a valid .ber map file"
# define INVALID_PATH "Error\nPath to objectives is not valid"
# define INVALID_MAP "Error\nInvalid map, it's not quite right"

/* ************************************************************************** */
/*                                 Struct                                     */
/* ************************************************************************** */

typedef struct s_game
{
	int				y_sp;
	int				x_sp;
	int				player_count;
	int				player;
	int				exit_count;
	int				exit;
	int				exit_flag;
	int				collectable_count;
	int				collectable;
	int				mapwidth;
	int				maphight;
	int				y_sz;
	int				x_sz;
	int				sq_sz;
	int				steps;
	char			**map;

	mlx_t			*mlx;

	mlx_image_t		*wall;
	mlx_image_t		*back_g;
	mlx_image_t		*goal;
	mlx_image_t		*p_front;
	mlx_image_t		*p_back;
	mlx_image_t		*p_right;
	mlx_image_t		*p_left;
	mlx_image_t		**tokens;

	mlx_texture_t	*wall_txt;
	mlx_texture_t	*back_g_txt;
	mlx_texture_t	*goal_txt;
	mlx_texture_t	*ring_txt;
	mlx_texture_t	*p_front_txt;
	mlx_texture_t	*p_back_txt;
	mlx_texture_t	*p_right_txt;
	mlx_texture_t	*p_left_txt;

}	t_game;

/* ************************************************************************** */
/*                               Main functions                               */
/* ************************************************************************** */

int		main(int argc, char **argv);

/* ************************************************************************** */
/*                            Map check functions                             */
/* ************************************************************************** */

void	read_map(char *str, t_game *game, int fd);
void	check_map_width(t_game *game);
void	check_map_borders(t_game *game);
void	check_map_content(t_game *game);
void	map_check(char *map_file, t_game *game);

/* ************************************************************************** */
/*                          Map check utils functions                         */
/* ************************************************************************** */

void	argument_check(char *argv);
void	check_p_e_c(t_game *game);
int		ft_find_char(char *str, char c);
void	check_real_hight(char *str, t_game *game, char *two_d_array);

/* ************************************************************************** */
/*                           Ft floodfill functions                           */
/* ************************************************************************** */

void	get_p_position(t_game *game);
void	ft_floodfill(t_game *game);
void	fill(char **map, int y_sp, int x_sp, t_game *game);
void	restore_map(t_game *game);

/* ************************************************************************** */
/*                             Init game functions                            */
/* ************************************************************************** */

void	get_texture(t_game *game);
void	get_image(t_game *game);
void	resize_images(t_game *game);
void	init_game(t_game *game);
void	put_player(t_game *game);

/* ************************************************************************** */
/*                             Put images functions                           */
/* ************************************************************************** */

void	put_img_to_window(t_game *game);
void	put_player_images(int i, int j, t_game *game);
void	put_collectable_image(t_game *game);
void	remove_textures(t_game *game);
void	remove_images(t_game *game);

/* ************************************************************************** */
/*                             Movement functions                             */
/* ************************************************************************** */

void	key_actions(mlx_key_data_t keydata, void *param);
void	move_left(t_game *game);
void	move_down(t_game *game);
void	move_right(t_game *game);
void	move_up(t_game *game);

/* ************************************************************************** */
/*                            Update moves functions                          */
/* ************************************************************************** */

void	picking_up_collectable(t_game *game);
void	update_left(t_game *game);
void	update_down(t_game *game);
void	update_right(t_game *game);
void	update_up(t_game *game);

/* ************************************************************************** */
/*                               Error functions                              */
/* ************************************************************************** */

void	invalid_map(char *str, t_game *game);
void	failed_to_open(char *str, char *two_d_array);
void	map_file_error(char *str, char *two_d_array);
void	ft_free_mlx(t_game *game, int option);

#endif