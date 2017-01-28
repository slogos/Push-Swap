# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slogos <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/02 00:09:06 by slogos            #+#    #+#              #
#    Updated: 2017/01/02 00:09:10 by slogos           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT		= 	libft/libftprintf.a
NAME		= 	swap.a
FILE_PS		= 	push_swap
FILE_CK		= 	checker
CC 			= 	gcc
CFLAGS		= 	-Wall -Werror -Wextra

SRC_PS 		= 	push_swap.c
SRC_CK		= 	checker.c
SRC_NAME 	= 	check_input.c check_valid.c checker_print.c checker_tools.c \
				ft_brut_force_one.c ft_brut_force_two.c ft_delete.c \
				ft_moves.c ft_operations_one.c ft_operations_two.c \
				ft_solve_tools.c push_swap_tools.c rotate.c rotate_rev.c \
				solver.c swap_push.c

OBJ_NAME = $(SRC_NAME:.c=.o)
AR = ar rc
RLIB = ranlib
RM = rm -f

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	$(CC) -c $(CFLAGS) $(SRC_NAME)
	$(AR) $(NAME) $(OBJ_NAME)
	$(RLIB) $(NAME)
	$(CC) $(CFLAGS) -o $(FILE_PS) $(SRC_PS) $(NAME) $(LIBFT) 
	$(CC) $(CFLAGS) -o $(FILE_CK) $(SRC_CK) $(NAME) $(LIBFT) 
	make clean

clean:
	$(RM) $(OBJ_NAME)
fclean: clean
	$(RM) $(NAME) $(FILE_PS) $(FILE_CK)
re: fclean all