# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 04:49:28 by bamssaye          #+#    #+#              #
#    Updated: 2024/02/05 03:49:45 by bamssaye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client server
NAME_BONUS  = client_bonus server_bonus

UTILS_M = utils/minitalk_utils.c
UTILS_B = utils/minitalk_bonus_utils.c
CLIENT_M = client.c
SERVER_M = server.c
CLIENT_B = client_bonus.c
SERVER_B = server_bonus.c

CC = cc
CFLAGS = -Wall -Wextra -Werror


all : $(NAME)

$(NAME): $(UTILS_M) $(CLIENT_M) $(SERVER_M) $(SERVER_C)
	@$(CC) $(CFLAGS) $(CLIENT_M) $(UTILS_M) -o client
	@$(CC) $(CFLAGS) $(SERVER_M) $(UTILS_M) -o server
	@echo "Mandatory Part : Compilation done."
	
bonus:$(NAME_BONUS)
	
$(NAME_BONUS): $(UTILS_B) $(CLIENT_B) $(SERVER_B) $(SERVER_B)
		@$(CC) $(CFLAGS) $(CLIENT_B) $(UTILS_B) -o client_bonus
		@$(CC) $(CFLAGS) $(SERVER_B) $(UTILS_B) -o server_bonus
		@echo "Bonus part : Compilation done."

clean :	
	@$(RM) client server client_bonus server_bonus
fclean : clean
	
re : fclean all

.PHONY : all, clean, fclean, re, bonus
