# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bamssaye <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 04:49:28 by bamssaye          #+#    #+#              #
#    Updated: 2024/02/01 15:00:30 by bamssaye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =
CLINET  = client
SERVER = server
CC = CC
CFLAGS = -Wall -Wextra -Werror
LIBFT = src/libft 
FT_PRINTF = src/ft_printf


all : $(NAME)

$(NAME) : $(CLINET) $(SERVER)

$(CLINET) : $(LIBFT) $(FT_PRINTF)

$(LIBFT):
	@ $(MAKE) -C (LIBFT)
$(FT_PRINTF);
	@ $(MAKE) -C ./libft

clean :

fclean : clean

re : 

.PHONY : all, clean, fclean, re
.SECONDARY : 