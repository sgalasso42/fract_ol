# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/14 15:38:31 by sgalasso          #+#    #+#              #
#    Updated: 2018/10/24 12:28:55 by sgalasso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = srcs/main.c \
	  srcs/ft_init_fractol.c \
	  srcs/ft_mouse.c \
	  srcs/ft_event.c \
	  srcs/ft_do_fract.c \
	  srcs/ft_julia.c \
	  srcs/ft_mandelbrot.c \
	  srcs/ft_put_infos.c \
	  srcs/inputs/ft_key_thread.c \
	  srcs/inputs/ft_key_iter.c \
	  srcs/inputs/ft_key_space.c \
	  srcs/inputs/ft_key_move.c \
	  srcs/inputs/ft_key_zoom.c \
	  srcs/inputs/ft_key_fract.c \
	  srcs/inputs/ft_key_flags.c \

OBJ = $(SRC:.c=.o)

INCLUDES = includes/

PTHREAD = -l pthread

MLX = -L ./minilibx_macos -lmlx -framework OpenGL -framework AppKit

all: libmlx lib $(NAME)

$(NAME):	$(OBJ)
	gcc -Wall -Wextra -Werror -o $(NAME) libft/libft.a $(OBJ) -I $(INCLUDES) $(MLX) $(PTHREAD)

lib:
	make -C libft/

libmlx:
	make -C minilibx_macos/

%.o: %.c $(INCLUDES)fractol.h Makefile
	gcc -Wall -Wextra -Werror -o $@ -c $< -I $(INCLUDES)

clean:
	rm -f $(OBJ) && make -C libft/ clean && make -C minilibx_macos/ clean

fclean:		clean
	rm -f $(NAME) && make -C libft/ fclean

re:			fclean all
