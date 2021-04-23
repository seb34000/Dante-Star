##
## EPITECH PROJECT, 2021
## Untitled (Workspace)
## File description:
## Makefile
##

all:
	make -C ./generator
	make -C ./solver
	@ echo "\033[1;36m[GENERATOR & SOLVER COMPILED]\033[0m"

clean:
	make clean -C ./generator/
	make clean -C ./solver
	@ echo "\033[1;36m[GENERATOR & SOLVER CLEAN]\033[0m"

fclean:
	make fclean -C ./generator/
	make fclean -C ./solver/
	@ echo "\033[1;36m[GENERATOR & SOLVER FCLEAN]\033[0m"

re: fclean all