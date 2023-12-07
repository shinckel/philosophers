# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shinckel <shinckel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 18:17:42 by shinckel          #+#    #+#              #
#    Updated: 2023/12/07 20:51:23 by shinckel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# how to add a folder for object files?

NAME := philo
CC := cc
CFLAGS := -Wall -Wextra -Werror -Iheader -g -pthread
# CFLAGS += -fsanitize=thread

# SRC := $(wildcard src/*.c)
SRC := 	src/init.c \
		src/monitor.c \
		src/philo.c \
		src/routine_actions.c \
		src/thread.c \
		src/utils.c
		
OBJ := $(SRC:.c=.o)

# Define colors
RED := \033[1;41m
GREEN := \033[1;42m
RESET := \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN) Let's eat, PHILOSOPERS! $(RESET)"

clean:
	@rm -f $(OBJ)
	@echo "$(RED) Remove objects & .txt files $(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED) Remove $(NAME) $(RESET)"

re: fclean all

# actions that should be executed when the target is invoked
.PHONY: all clean fclean re