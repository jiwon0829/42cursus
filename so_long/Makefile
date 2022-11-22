# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 16:00:18 by jiwonhan          #+#    #+#              #
#    Updated: 2022/11/11 04:48:25 by jiwonhan         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = cc -g
CFLAGS = -Wall -Wextra -Werror -Iinclude
MLX =  -Lmlx -lmlx -framework OpenGL -framework AppKit

NAME = so_long

SRCS = src/so_long/so_long.c src/so_long/utils.c src/so_long/game.c \
		src/so_long/map_check.c src/so_long/ft_split.c src/so_long/map_setting.c\
		src/so_long/key_event.c src/so_long/ft_itoa.c src/so_long/img_setting.c \
		src/gnl/get_next_line.c src/gnl/get_next_line_utils.c \
		src/so_long/is_valid_path.c src/so_long/memory_utils.c

OBJS = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(MLX) -o $(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean
	@$(MAKE)

.PHONY : all clean fclean re