# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plang <plang@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 13:34:43 by plang             #+#    #+#              #
#    Updated: 2024/08/05 14:37:27 by plang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

CC			= @cc

CFLAGS 		= -Werror -Wextra -Wall -Wunreachable-code -Ofast

LIBFT_PATH	= ./libft

LIBFT		= $(LIBFT_PATH)/libft.a

MLX_FLAGS	= -ldl -lglfw -pthread -lm -L"/Users/$(USER)/.brew/opt/glfw/lib/"

MLX_PATH	= ./MLX42

LIBMLX		= $(MLX_PATH)/build/libmlx42.a $(MLX_FLAGS)

HEADERS		= -I $(MLX_PATH)/include

SRCS		= src/main.c\
				src/map_check.c \
				src/map_check_utils.c \
				src/ft_floodfill.c \
				src/init_game.c \
				src/put_images.c \
				src/movement.c \
				src/update_moves.c \
				src/error_functions.c \

OBJS		= $(SRCS:.c=.o)

all:			libmlx $(NAME)

$(LIBFT):
	@make -C	$(LIBFT_PATH)

libmlx:
	@cmake		$(MLX_PATH) -B $(MLX_PATH)/build && make -C $(MLX_PATH)/build -j4

$(NAME):		$(LIBFT) $(OBJS)
	$(CC)		$(CFLAGS) $(HEADERS) $(OBJS) $(LIBFT) $(LIBMLX) -o $(NAME)
	@echo "Program compiled!"

clean:
	@rm -f		$(OBJS)
	@make -C	$(LIBFT_PATH) fclean
	@echo "Removed -o files"

fclean: clean
	@rm -f		$(NAME)
	@rm -rf 	$(MLX_PATH)/build
	@echo "Removed program!"

re: fclean 		libmlx $(NAME)

.PHONY: all clean fclean re libft libmlx