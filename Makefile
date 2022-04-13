##
## EPITECH PROJECT, 2021
## makefile
## File description:
## bsbsq
##

SRC	=	src/bsq.c\
		src/bsq_bis.c\
		src/my_str_to_word_array_bsq.c\

SRC_TEST	=	tests/test_open.c

OBJ	=	$(SRC:.c=.o)

OBJ2	=	$(SRC_TEST:.c=.o)

NAME	=	bsq

LIB_FLAGS	=	-L./lib/my -lmy

CFLAGS	=	-Wall -Wextra -I./include -g3

CRIT_FLAGS	=	--coverage -lcriterion

NAME_TEST	=	unit_test

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./lib/my
	gcc -o $(NAME) $(SRC) main.c $(CFLAGS) $(LIB_FLAGS)

clean:
	rm -f $(OBJ)
	make -C ./lib/my
	rm -f -r *~
	rm -f *gc*

fclean: clean
	make -C ./lib/my fclean
	rm -f $(NAME)
	rm -f $(NAME_TEST)

unit_test: $(OBJ) $(OBJ2)
	make -C ./lib/my
	gcc -o $(NAME_TEST) $(SRC) $(SRC_TEST) $(CFLAGS) $(LIB_FLAGS) $(CRIT_FLAGS)

tests_run: unit_test
	./$(NAME_TEST)
	gcovr --exclude tests/
	gcovr -b --exclude tests/

re: fclean all

.PHONY: all clean fclean unit_test tests_run re
