##
## EPITECH PROJECT, 2021
## Untitled (Workspace)
## File description:
## Makefile
##

CC		=	@ gcc -O3 -g3 -pg
SRC		=	$(wildcard src/*.c)
OBJ		=	$(SRC:.c=.o)
LIB		=	-L ./lib/ -lmy
NAME	=	generator
CFLAG	+=	-I	./../include/
CFLAG	+=	-W -Wall -Wextra

all: $(NAME)

$(NAME): complib $(OBJ)
	@ $(CC) $(OBJ) -o $(NAME) $(LIB) $(CFLAG)
	@ make clean
	@ echo "\033[1;36m[GENERATOR COMPILED]\033[0m"

complib:
	@ make -C ./lib/
	@ echo "\033[1;36m[LIB COMPILED]\033[0m"

clean:
	@ $(RM) $(OBJ)
	@ make clean -C ./lib/
	@ echo "\033[1;32m[CLEAN OK]\033[0m"

fclean: clean
	@ $(RM) $(NAME)
	@ make fclean -C ./lib/
	@ echo "\033[1;32m[FCLEAN OK]\033[0m"

re: fclean all
