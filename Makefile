##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile root dante
##

all:	generator solver

generator:
	make -C generator/
	@echo -e "\033[00m\033[33mgenerator ==> ready !\033[00m"

solver:
	make -C solver/
	@echo -e "\033[00m\033[31msolver ==> ready !\033[00m"

tests_run:
	make -C tests/ fclean
	make -C tests/
	gcovr

bonus_run:
	make -C bonus/

clean:
	make -C tests/ clean
	make -C bonus/ clean
	make -C generator/ clean
	make -C solver/ clean
	rm -f $(OBJ)

fclean: clean
	make -C tests/ fclean
	make -C bonus/ fclean
	make -C generator/ fclean
	make -C solver/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all generator solver tests_run
