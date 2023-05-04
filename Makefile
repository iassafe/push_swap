# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 13:41:12 by iassafe           #+#    #+#              #
#    Updated: 2023/05/04 17:02:33 by iassafe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
SRC = push_swap.c utils_push_swap.c libft.c parcing.c swap.c rotate.c rev_rotate.c push.c sort.c
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
