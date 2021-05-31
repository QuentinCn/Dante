##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile root generator
##

SRC	=	main.c			\
		generator.c		\
		error_handling.c	\
		my_array_len.c		\
		manage_pos.c		\
		map.c			\
		is_in_angle.c		\
		imperfect.c		\
		perfect.c

OBJ	= 	${SRC:.c=.o}

NAME	=	generator

CFLAGS	= 	-W -Wall -Wextra

CPPFLAGS= 	-I./../include

all:	binairy

binairy: $(OBJ)
	gcc -o $(NAME) $(CFLAGS) $(SRC) $(CPPFLAGS) -g3

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	clear

re: fclean all

.PHONY: clean fclean re all binairy
