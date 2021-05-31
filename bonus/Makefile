##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile bonus solver
##

SRC	=	solver_bonus.c				\
		../solver/open_read.c			\
		../solver/my_str_to_word_array.c	\
		../solver/main.c			\
		display_with_color.c

OBJ	= 	${SRC:.c=.o}

NAME	= 	solver_bonus

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
