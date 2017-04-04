# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ichemenc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/04 18:40:59 by ichemenc          #+#    #+#              #
#    Updated: 2017/04/04 18:42:19 by ichemenc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
	LIBRARY = libft

all: $(NAME)

$(NAME):
		make -C $(LIBRARY)
			$(CC) $(CFLAGS) -c $(SRC) -I $(LIBRARY)
				$(CC) $(OBJ) -L $(LIBRARY) -lft -o $(NAME)

.PHONY: clean

clean:
		make -C $(LIBRARY) clean
			/bin/rm -rf $(OBJ)
				@echo "Delete C object files"

fclean: clean
		/bin/rm -f $(NAME)
			/bin/rm -f $(LIBRARY)/libft.a
				@echo "Delete $(NAME)"
					@echo "Delete $(LIBRARY)/libft.a"

re: fclean all
