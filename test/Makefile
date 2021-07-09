# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/26 17:06:32 by fmanetti          #+#    #+#              #
#    Updated: 2021/07/09 14:12:14 by fmanetti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME                    =       cont

SOURCE                  =       main.cpp

OBJ                     =       $(SOURCE:%.cpp=%.o)

HEADERS                 =       

CC                      =       clang++

CFLAGS                  =       -Wall -Wextra -Werror -std=c++98
FSANITIZE               =       -g3 -O0 -fsanitize=address

RED                     =       \033[0;31m
GREEN                   =       \033[0;32m
NO_COLOR                =       \033[0m

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	@printf "[ $(NAME) ] Compiling...\r"
	@($(CC) -o $(NAME) $(SOURCE) $(INCLUDE) $(CFLAGS))
	@printf "[ $(NAME) ] Created $(GREEN)Successfully\n$(NO_COLOR)" $(SUCCESS)

san:
	@printf "[ $(NAME) ] Compiling with fsanitize...\r"
	@($(CC) -o $(NAME) $(SOURCE) $(LIBRARY) $(CFLAGS) $(FSANITIZE))
	@printf "[ $(NAME) ] Created $(GREEN)Successfully$(NO_COLOR) with fsanitize\n" $(SUCCESS)

clean:
	@/bin/rm -f $(OBJ)
	@printf "Object files $(RED)removed\n$(NO_COLOR)"

fclean: clean
	@/bin/rm -rf $(NAME)
	@/bin/rm -rf .vscode
	@printf "[ $(NAME) ] $(RED)removed\n$(NO_COLOR)"

re: fclean all

.PHONY: all clean fclean re

.SILENT: