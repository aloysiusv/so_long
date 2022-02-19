# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 16:06:20 by lrandria          #+#    #+#              #
#    Updated: 2022/02/19 15:17:22 by lrandria         ###   ########.fr        #
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
HDR			=	./includes_bonus/so_long_bonus.h
S			=	./srcs_bonus/
SRCS		=	$(S)0_main_bonus.c \
				$(S)1_map_check_bonus.c $(S)2_map_fill_bonus.c \
				$(S)3_init_txtr_bonus.c $(S)4_init_moves_bonus.c \
				$(S)5_game_start_bonus.c $(S)6_game_next_frame_bonus.c \
				$(S)7_utils_draw_bonus.c $(S)8_utils_free_bonus.c

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