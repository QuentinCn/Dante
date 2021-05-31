##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile root solver
##

SRC	=	solver.c			\
		open_read.c			\
		my_str_to_word_array.c		\
		main.c				\
		find_path.c 		\
		../generator/my_array_len.c

OBJ	= 	${SRC:.c=.o}

NAME	= 	solver

CFLAGS	= 	-W -Wall -Wextra

CPPFLAGS= 	-I../include

all:	binairy

binairy: $(OBJ)
	gcc -o $(NAME) $(CFLAGS) $(SRC) $(CPPFLAGS)

clean:
	$(RM) $(OBJ) *~ \#*\#

fclean: clean
	rm -f $(NAME)
	clear

re: fclean all

.PHONY: clean fclean re all binairy
