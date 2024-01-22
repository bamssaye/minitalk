# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 04:49:28 by bamssaye          #+#    #+#              #
#    Updated: 2024/01/22 06:28:36 by bamssaye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLINET  = client
SERVER = server
CC = CC
CFLAGS = -Wall -Wextra -Werror
LIBFT = src/libft 
GNLINE = src/getnextline


all : $(NAME)

clean :

fclean : clean

re : 

.PHONY : all, clean, fclean, re
.SECONDARY : 