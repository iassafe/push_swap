# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 13:41:12 by iassafe           #+#    #+#              #
#    Updated: 2023/05/16 15:16:00 by iassafe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
CFLAGS = -Wall -Wextra -Werror
SRC =	mandatory/push_swap.c \
		mandatory/utils.c \
		mandatory/libft.c \
		mandatory/parsing.c \
		mandatory/swap.c \
		mandatory/rotate.c \
		mandatory/rev_rotate.c \
		mandatory/push.c \
		mandatory/sort.c \
		mandatory/table.c \
		mandatory/push_stack_b.c
INCLUDE = mandatory/push_swap.h

SRCB = 	bonus/push_swap.c \
		bonus/utils.c \
		bonus/libft.c \
		bonus/parsing.c \
		bonus/swap.c \
		bonus/rotate.c \
		bonus/rev_rotate.c \
		bonus/push.c \
		bonus/table.c \
		bonus/get_next_line.c \
		bonus/other_utils.c
INCLUDEB = bonus/push_swap_bonus.h

OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)

all : $(NAME)

bonus : $(BONUS)

push_swap : $(OBJ) $(INCLUDE)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

checker : $(OBJB) $(INCLUDEB)
	$(CC) $(CFLAGS) $(OBJB) -o $(BONUS)

mandatory/%.o : mandatory/%.c $(INCLUDE)
	$(CC) $(CFLAGS) -o $@ -c $<

bonus/%.o : bonus/%.c $(INCLUDEB)
	$(CC) $(CFLAGS) -o $@ -c $<

clean :
	rm -rf $(OBJ) $(OBJB)

fclean : clean
	rm -rf $(NAME) $(BONUS)

re : fclean all
