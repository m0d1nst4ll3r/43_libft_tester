# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/08 10:29:07 by rapohlen          #+#    #+#              #
#    Updated: 2025/11/08 16:48:16 by rapohlen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= main.c error.c init.c free.c util.c util2.c tester.c \
			  itoa.c substr.c strsplit.c strjoin.c strtrim.c \
			  list.c list2.c \
			  test_strnstr.c \
			  test_isascii.c \
			  test_isalpha.c \
			  test_isalnum.c \
			  test_isprint.c \
			  test_isdigit.c \
			  test_tolower.c \
			  test_toupper.c \
			  test_atoi.c \
			  test_bzero.c \
			  test_memset.c \
			  test_memchr.c \
			  test_strchr.c \
			  test_strrchr.c \
			  test_memcpy.c \
			  test_strlcpy.c \
			  test_strlen.c \
			  test_memcmp.c \
			  test_strncmp.c \
			  test_memmove.c \
			  test_strdup.c \
			  test_strlcat.c \
			  test_calloc.c \
			  test_itoa.c \
			  test_substr.c \
			  test_join.c \
			  test_split.c \
			  test_strtrim.c \
			  test_striteri.c \
			  test_strmapi.c

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
