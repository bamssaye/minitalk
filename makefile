# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bamssaye <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 04:49:28 by bamssaye          #+#    #+#              #
#    Updated: 2024/02/01 16:10:55 by bamssaye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =
CLINET  = client
SERVER = server
CC = CC
CFLAGS = -Wall -Wextra -Werror
LIBFT = src/libft 
FT_PRINTF = src/ft_printf
CLIENT_C = client.c
SERVER_C = server.c
LIBFT_A = libft.a
FT_PRINTF_A = libftprintf.a

all : $(SERVER)

$(LIBFT):
	$(MAKE) -C $(LIBFT)
$(SERVER): $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT) -o server

clean :
	rm *.a

fclean : clean

re : fclean all

.PHONY : all, clean, fclean, re
.SECONDARY : $(CLIENT_C)