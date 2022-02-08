# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 16:06:20 by lrandria          #+#    #+#              #
#    Updated: 2021/12/03 01:25:09 by lrandria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
MLX			=	minilibx-linux/libmlx.a
CC			=	gcc
CFLAGS		=	-Wall -Wextra
LIBS		=	-L ./minilibx-linux -lmlx -lXext -lX11 -lm -lbsd
OBJS		=	$(SRCS:.c=.o)
HDR			=	so_long.h
SRCS		=	main.c

all:		$(MLX) $(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)

$(MLX):
			make -C ./minilibx-linux

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