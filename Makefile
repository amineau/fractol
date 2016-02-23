NAME = fractol

CC = gcc
LFTPATCH = ./libft/
LMLXPATCH = ./minilibx/
LIBS = -L$(LMLXPATCH) -lmlx -framework OpenGL -framework AppKit -L$(LFTPATCH) -lft 
FLAGS = -Wall -Werror -Wextra -O2
SRC = main.c \
	  hook.c \
	  display.c \
	  mandelbrot.c \
	  julia.c \
	  carpet.c \
	  image.c \
	  ft_error.c

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	make -C $(LFTPATCH)
	make -C $(LMLXPATCH)
	$(CC) $(FLAGS) -c $(SRC) 
	$(CC) $(OBJ) $(LIBS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
