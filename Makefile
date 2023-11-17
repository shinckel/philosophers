# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shinckel <shinckel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 18:17:42 by shinckel          #+#    #+#              #
#    Updated: 2023/11/17 18:19:16 by shinckel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philo
CC := cc
CFLAGS := -Wall -Wextra -Werror -Iheader -g
CFLAGS += -fsanitize=address

SRC := $(wildcard src/*.c)
OBJ := $(SRC:.c=.o)
LIBFT_DIR := ./libft
LIBFT := $(LIBFT_DIR)/libft.a

# Define colors
RED := \033[1;41m
GREEN := \033[1;42m
RESET := \033[0m

all: $(NAME)

# target -> library file -> invoke the make utility recursively
# -C allows to build targets in different directory than where Makefile resides
$(LIBFT):
	$(MAKE) bonus -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@git submodule update --init --recursive
	@echo "$(GREEN) Ready to PUSH_SWAP $(RESET)"

clean:
	@rm -f $(OBJ)
	@echo "$(RED) Remove objects & .txt files $(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED) Remove $(NAME) $(RESET)"

re: fclean all

clean_libft:
	@$(MAKE) -C $(LIBFT_DIR) fclean

# actions that should be executed when the target is invoked
.PHONY: all clean fclean re clean_libft submodule