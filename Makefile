##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Lucas Duboisse
##

NAME	=	projTester

SRC	=	src/main.c		\
		src/sort.c		\
		src/pars.c		\
		src/free.c		\
		src/struct.c		\
		src/tree_print.c		\
		src/command.c		\
		src/fnd_bin.c		\
		src/str_to_word_tab.c	\
		src/fnd_args.c		\
		src/args_print.c	\
		src/other.c		\
		src/exec_process.c

OBJ	=	$(SRC:.c=.o)

GCC_ARG	=		-L$(LIB_DIR) -l$(LIB) -I$(INC_DIR)
GCC_ARG_DEBUG	=	-L$(LIB_DIR) -l$(LIB) -I$(INC_DIR) -g
CFLAGS	=		-g -W -Wall -Wextra -Iinclude/

all:		$(NAME)

$(NAME):
		gcc -o $(NAME) $(SRC) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
