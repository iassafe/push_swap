# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 13:41:12 by iassafe           #+#    #+#              #
#    Updated: 2023/05/15 16:58:52 by iassafe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
CFLAGS = -Wall -Wextra -Werror
SRC = push_swap.c utils.c libft.c parsing.c swap.c \
rotate.c rev_rotate.c push.c table.c get_next_line.c other_utils.c
INCLUDE = push_swap_bonus.h

OBJ = $(SRC:.c=.o)

all : $(NAME)

checker : $(OBJ) $(INCLUDE)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.c $(INCLUDE)
	$(CC) $(CFLAGS) -o $@ -c $<

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
