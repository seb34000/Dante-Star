##
## EPITECH PROJECT, 2021
## Untitled (Workspace)
## File description:
## Makefile
##

CC	=	@ gcc -g -g2

SRC	=	$(wildcard *.c)

OBJ	= $(SRC:.c=.o)

LIB	=	libmy.a

INC = 	./include/maze.h

CFLAGS = -W -Wall -Wextra

all:	$(LIB)

$(LIB):	$(OBJ)
		@ ar rsc $(LIB) $(OBJ)
		#@ mkdir -p ../include/
		#@ cp include/*.h ../include/
		@ echo "\033[1;36m[LIB COMPILED]\033[0m"

clean:
	@ rm -f $(OBJ)

fclean: clean
	@ rm -f $(LIB)

re:	fclean all