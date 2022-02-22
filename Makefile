# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 16:06:20 by lrandria          #+#    #+#              #
#    Updated: 2022/02/22 15:55:58 by lrandria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
NAME_BONUS	=	so_long_bonus
MLX			=	minilibx-linux/libmlx.a
LFT			= 	libft/libft.a
CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror
INC			=	-I ./
LIBS		=	-L ./libft -lft -L ./minilibx-linux -lmlx -lXext -lX11 -lm -lbsd
OBJS		=	$(SRCS:.c=.o)
OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)
HDR_BONUS	=	./bonus/includes_bonus/so_long_bonus.h
HDR			=	./includes/so_long.h
S			=	./srcs/
S_BONUS		=	./bonus/srcs_bonus/
SRCS		=	$(S)0_main.c \
				$(S)1_map_check.c $(S)2_map_fill.c \
				$(S)3_game_init.c $(S)4_game_start.c $(S)5_game_next_frame.c \
				$(S)6_utils_draw.c $(S)7_utils_free.c

SRCS_BONUS	=	$(S_BONUS)0_main_bonus.c \
				$(S_BONUS)1_map_check_bonus.c $(S_BONUS)2_map_fill_bonus.c \
				$(S_BONUS)3_init_txtr_bonus.c $(S_BONUS)4_init_moves_bonus.c \
				$(S_BONUS)5_game_start_bonus.c \
				$(S_BONUS)6_game_next_frame_bonus.c \
				$(S_BONUS)7_utils_draw_bonus.c $(S_BONUS)8_utils_free_bonus.c

all:			$(MLX) $(LFT) $(NAME) $(NAME_BONUS)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)

bonus:			$(MLX) $(LFT) $(NAME_BONUS)

$(NAME_BONUS):	$(OBJS_BONUS)
				$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS) $(LIBS)

$(MLX):
			make -C ./minilibx-linux
$(LFT):
			make -C ./libft

%.o:		%.c $(HDR) $(HDR_BONUS)
			$(CC) $(CFLAGS) $(INC) -c -o $@ $< 

clean:
			rm -rf $(OBJS) $(OBJS_BONUS)

fclean:		clean
			rm -rf $(NAME) $(NAME_BONUS)

re:			fclean all

.PHONY:		all bonus clean fclean re