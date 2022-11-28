# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 17:42:04 by jiwonhan          #+#    #+#              #
#    Updated: 2022/11/21 18:50:23 by jiwonhan         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SERVER = server
CLIENT = client

INCLUDES = minitalk.h

SERVER_SRCS = server.c utils.c ft_print.c
CLIENT_SRCS = client.c utils.c ft_print.c

SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

all:	$(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJS)
	@$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJS)

$(CLIENT): $(CLIENT_OBJS)
	@$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)

fclean: clean
	@$(RM) $(SERVER) $(CLIENT)

re: fclean
	@$(MAKE)

.PHONY : all clean fclean re