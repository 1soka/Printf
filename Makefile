# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ******** <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/20 14:05:28 by ********          #+#    #+#              #
#    Updated: 2026/10/27 17:50:31 by ********         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
HEADERS = .
FLAGS = -Wall -Wextra -Werror -I $(HEADERS)
SRCS = ft_printf.c ft_printf_utils.c
OBJECTS = $(SRCS:.c=.o)
NAME = libftprintf.a

.DEFAULT: all

.PHONY: help clean fclean re all

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

.c.o:
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
