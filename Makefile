# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/08 10:29:07 by rapohlen          #+#    #+#              #
#    Updated: 2025/10/23 17:21:04 by rapohlen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= main.c error.c util.c tester.c \
			  test_strnstr.c \
			  test_isascii.c \
			  test_isalpha.c \
			  test_isalnum.c \
			  test_isprint.c \
			  test_isdigit.c \
			  test_tolower.c \
			  test_toupper.c \
			  test_atoi.c

INCDIRS		= includes/ libft/
SRCDIRS		= srcs/

INCFLAG		= $(foreach D, $(INCDIRS), -I $(D))
SRCS		= $(addprefix $(SRCDIRS), $(SRC))
OBJS		= $(SRCS:.c=.o)


CC			= cc
CFLAGS		= -Wall -Wextra -Werror $(INCFLAG)

LIBS		= libft/libft.a \
			  -lbsd

NAME		= libft_tester

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C libft
			$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
			make clean -C libft
			rm -f $(OBJS)

fclean:		clean
			make fclean -C libft
			rm -f $(NAME)

re:			fclean all

.PHONY: clean fclean all
