# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvapari <alvapari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/06 00:12:53 by alvapari          #+#    #+#              #
#    Updated: 2024/11/04 12:43:03 by alvapari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers

CFLAGS  = -Wall -Wextra -Werror -g -I ./include/

# Para añadirlo make FSANITIZE_ADDRESS=1
ifdef FSANITIZE_ADDRESS
	CFLAGS += -fsanitize=address
# -fsanitize=thread 
endif

CC = clang

SRC_DIR = ./
OBJ_DIR = obj/

SRC_FILES = exit init main monitor print_error print_steps routines\
take_forks utils utils_two

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
DEP = $(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
