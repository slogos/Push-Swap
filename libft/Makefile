# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slogos <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/28 00:46:45 by slogos            #+#    #+#              #
#    Updated: 2016/11/28 00:46:48 by slogos           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	 = 	libftprintf.a
FILE 	 =  ft_printf
CC	 	 = 	gcc
CFLAGS	 =	-Wall -Werror -Wextra

SRC_NAME =  ft_printf.c ft_colors.c ft_conv_b.c ft_conv_c.c ft_conv_d_i.c \
			ft_conv_f.c ft_conv_flt_0.c ft_conv_hex_0.c ft_conv_hex_1.c \
			ft_conv_int_0.c ft_conv_int_1.c ft_conv_o.c ft_conv_oct_0.c \
			ft_conv_oct_1.c ft_conv_p.c ft_conv_percent.c ft_conv_s.c \
			ft_conv_str_0.c ft_conv_u.c ft_conv_uni_0.c ft_conv_uni_1.c \
			ft_conv_wstr.c ft_conv_x.c ft_conv_char_0.c ft_flags_0.c \
			ft_flags_1.c ft_printf_conv.c ft_tools_binary.c ft_tools_itoa.c \
			ft_tools_nbr.c ft_tools_wchar.c ft_isdigit.c ft_isnumber.c \
			ft_nbrlen.c ft_nbrlen_base.c ft_strlen.c ft_atoi.c ft_putchar.c \
			ft_putnbr.c ft_putnbr_base.c ft_putstr.c ft_itoa_base.c \
			ft_strdel.c ft_strnew.c ft_bzero.c ft_memmove.c ft_isspace.c \
			ft_power.c ft_itoa.c ft_memset.c ft_memcpy.c ft_int_len.c \
			ft_lstnew.c ft_strdup.c ft_strsplit.c ft_lstnew_move.c \
			ft_lstnew_gnl.c ft_strchr.c ft_strcpy.c ft_strncat.c \
			ft_strndup.c ft_strnjoin.c get_next_line.c ft_strcmp.c \
			ft_strjoin.c

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
	make clean
clean:
	$(RM) $(OBJ_NAME)
fclean: clean
	$(RM) $(NAME) $(FILE)
re: fclean all
