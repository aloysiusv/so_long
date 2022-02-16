# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 16:06:20 by lrandria          #+#    #+#              #
#    Updated: 2022/02/16 18:07:23 by lrandria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
MLX			=	minilibx-linux/libmlx.a
LFT			= 	libft/libft.a
CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror
INC			=	-I ./
LIBS		=	-L ./libft -lft -L ./minilibx-linux -lmlx -lXext -lX11 -lm -lbsd
OBJS		=	$(SRCS:.c=.o)
HDR			=	./includes/so_long.h
S			=	./srcs/
SRCS		=	$(S)0_main.c \
				$(S)1_map_check.c $(S)2_map_fill.c $(S)3_map_print.c\
				$(S)4_game_init.c $(S)5_game_start.c $(S)6_game_next_frame.c \
				$(S)7_utils_draw.c $(S)8_utils_free.c

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
			$(CC) $(CFLAGS) $(INC) -c -o $@ $< 

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re