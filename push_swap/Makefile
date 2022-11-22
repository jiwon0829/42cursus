# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/14 02:00:52 by hanjiwon          #+#    #+#              #
#    Updated: 2022/10/28 16:36:15 by jiwonhan         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = cc -g
CFLAGS = -Wall -Wextra -Werror -Iinclude
RM = rm -rf

NAME = push_swap
CHECKER = checker

PUSH_SWAP_SRCS = src/push_swap.c
CHECKER_SRC = src/checker.c
UTILS_SRCS = src/command/command_push.c src/command/command_reverse_rotate.c \
			src/command/command_rotate.c src/command/command_swap.c \
			src/doubly_linked_list/list.c src/doubly_linked_list/list_utils.c \
			src/get_next_line/get_next_line.c src/get_next_line/get_next_line_utils.c \
			src/quick_sort/quick_sort.c src/quick_sort/quick_sort_a_utils.c \
			src/quick_sort/quick_sort_b_utils.c src/utils/atoi.c src/utils/ft_put.c \
			src/utils/ft_str.c src/utils/bubble_sort.c src/utils/is_valid.c \
			src/utils/memory.c src/utils/message.c src/utils/split.c \
			src/optimization/commands_optimization.c src/optimization/quick_sort_optimization.c \
			src/optimization/quick_sort_optimization2.c


OBJ_PUSH_SWAP = $(PUSH_SWAP_SRCS:.c=.o)
OBJ_CHECKER = $(CHECKER_SRC:.c=.o)
OBJ_UTILS = $(UTILS_SRCS:.c=.o)

all: $(NAME) $(CHECKER)

$(NAME): $(OBJ_PUSH_SWAP) $(OBJ_UTILS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ_PUSH_SWAP) $(OBJ_UTILS)

$(CHECKER): $(OBJ_CHECKER) $(OBJ_UTILS)
	@$(CC) $(CFLAGS) -o $(CHECKER) $(OBJ_CHECKER) $(OBJ_UTILS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_PUSH_SWAP) $(OBJ_CHECKER) $(OBJ_UTILS)

fclean: clean
	@$(RM) $(NAME) $(CHECKER)

re: fclean
	@$(MAKE)

.PHONY : all clean fclean re