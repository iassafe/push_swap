# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 13:41:12 by iassafe           #+#    #+#              #
#    Updated: 2023/05/15 16:57:20 by iassafe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
SRC = push_swap.c utils.c libft.c parsing.c swap.c \
rotate.c rev_rotate.c push.c sort.c table.c push_stack_b.c
INCLUDE = push_swap.h

OBJ = $(SRC:.c=.o)

all : $(NAME)

push_swap : $(OBJ) $(INCLUDE)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.c $(INCLUDE)
	$(CC) $(CFLAGS) -o $@ -c $<

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
