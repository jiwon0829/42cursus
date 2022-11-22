# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/17 11:57:27 by jiwonhan          #+#    #+#              #
#    Updated: 2022/09/18 16:51:53 by jiwonhan         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
LIBFT		= libft
LIBFT_LIB	= libft.a

CFLAG = -Wall -Wextra -Werror -c
AR = ar rc
RM = rm -f

SRC = ft_printf.c  ft_printf_utils.c ft_printf_hub.c ft_printf_hub2.c ft_printf_c.c ft_printf_base.c base_func.c
	
OBJ = $(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJ)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(AR) $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(CFLAG) $^ -I./ -o $@

bonus : all

clean :
	$(RM) $(OBJ)
	make clean -C $(LIBFT)

fclean : clean
	$(RM) $(NAME)
	rm -f $(LIBFT_LIB)
	make fclean -C $(LIBFT)

re : fclean all

.PHONY : all bonus clean fclean re
