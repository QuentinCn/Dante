##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile root matchstick
##

SRC	= 	tests_generator.c		\
		../generator/manage_pos.c	\
		../generator/is_in_angle.c	\
		../generator/map.c		\
		../generator/imperfect.c	\
		../generator/perfect.c		\
		../generator/generator.c	\
		../generator/my_array_len.c	\
		tests_solver.c			\
		../solver/find_path.c

OBJ	= 	${SRC:.c=.o}

NAME	= 	unit_test

CFLAGS	= 	-W -Wall -Wextra

UTFLAGS	=	--coverage -lcriterion

CPPFLAGS= 	-I./../include

all:	test_run

test_run: $(OBJ)
	gcc -o $(NAME) $(CFLAGS) $(SRC) $(CPPFLAGS) $(UTFLAGS)
	./unit_test

clean:
	rm -f $(OBJ)
	rm -f *.gc*

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all test_run
