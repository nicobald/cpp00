# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbaldes <nbaldes@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/04 14:51:25 by nbaldes           #+#    #+#              #
#    Updated: 2026/03/04 15:27:53 by nbaldes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

SRC =	phonebook.cpp \

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -cpp $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re