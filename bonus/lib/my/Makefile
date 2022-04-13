##
## EPITECH PROJECT, 2021
## Makefile for Day10
## File description:
## Task01
##

SRC	=	my_putstr.c	\
		my_putchar.c	\
		my_strlen.c	\
		my_strncpy.c	\
		my_strlen_buffer.c\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp my.h ../../include/
	cp $(NAME) ../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re:	fclean all
