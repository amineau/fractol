# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amineau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 15:32:27 by amineau           #+#    #+#              #
#    Updated: 2016/01/10 18:06:49 by amineau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

CC=gcc

FLAGS=-Wall -Werror -Wextra

SRC=ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_strlen.c ft_strdup.c \
	ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
	ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_strclr.c \
	ft_memset.c ft_memcpy.c ft_memchr.c ft_memccpy.c ft_memmove.c ft_memcmp.c \
	ft_bzero.c ft_isupper.c ft_islower.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
	ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_atoi.c ft_strnew.c \
	ft_memalloc.c ft_itoa.c ft_memdel.c ft_strdel.c ft_strequ.c ft_strnequ.c \
	ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strsub.c ft_strjoin.c \
	ft_strtrim.c ft_strsplit.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
	ft_lstmap.c ft_min.c ft_max.c ft_putnbrendl.c ft_strclnjoin.c ft_strndup.c \
	get_next_line.c ft_abs.c

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
