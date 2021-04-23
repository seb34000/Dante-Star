##
## EPITECH PROJECT, 2020
## Dante
## File description:
## Makefile
##

NAME	=	solver

SRCS	= 	./src/main.c \
		 	./src/init.c \
		 	./src/print.c \
		 	./src/path.c \
		 	./src/screen.c

OBJS	=	$(SRCS:.c=.o)

NBR_OF_FILES := $(words $(SRCS))

CC = gcc -g

RM	=	rm -f

CFLAGS += -I./include
CFLAGS += -W -Wall -Wextra -Wno-unused-parameter -O3 -pg

LIBLIST	=	liblist.a

all:	$(NAME)

$(NAME): $(OBJS)
	@ echo "\033[1;36m[ FILES COMPILED ] \033[0m \033[1;36m$(NBR_OF_FILES)\033[0m"
	$(CC) -o $(NAME) $(OBJS) -I./include -L./lib -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio
	@ echo "\033[1;35mBinary : \033[1;36m$(NAME)\033[1;35m created sucesfully.\033[0m"

clean:
	@ echo "\033[3;31mRemoving: \033[0m"
	@ echo "\033[3;31m$(OBJS)\033[0m" | tr ' ' '\n'
	@ $(RM) $(OBJS)
	@ $(RM) $(OBJLIST)
	@ $(RM) include/list.h


fclean:	clean
	@ echo "\033[3;31m./$(NAME)\033[0m"
	@ $(RM) $(NAME)

re: 	fclean all

%.o:	%.c
	@ echo "\033[1;35m[ OK ]\033[0m Compiling" $<
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: all clean fclean re