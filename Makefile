# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 16:06:20 by lrandria          #+#    #+#              #
#    Updated: 2022/02/13 18:22:12 by lrandria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
MLX			=	minilibx-linux/libmlx.a
LFT			= 	libft/libft.a
CC			=	clang
CFLAGS		=	-Wall -Wextra
LIBS		=	-L ./libft -lft -L ./minilibx-linux -lmlx -lXext -lX11 -lm -lbsd
OBJS		=	$(SRCS:.c=.o)
HDR			=	so_long.h
SRCS		=	main.c map_parsing.c map_errors.c \
				game_init.c game_draw.c game_moves.c \
				utils.c

all:		$(MLX) $(LFT) $(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)

$(MLX):
			make -C ./minilibx-linux
$(LFT):
			make -C ./libft

debug:		$(OBJS)
			$(CC) $(CFLAGS) -g3 -fsanitize=address $(OBJS) -o $(NAME) $(LIBS)

%.o:		%.c $(HDR)
			$(CC) $(CFLAGS) -c -o $@ $< 

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re