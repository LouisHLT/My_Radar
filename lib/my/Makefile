##
## EPITECH PROJECT, 2022
## TEK1_22-23
## File description:
## Makefile
##

SRC	=	my_putstr.c	\
		my_putchar.c	\
		my_strlen.c	\
		my_strcat.c	\
		my_put_nbr.c	\
		my_strcmp.c	\
		mini_printf.c	\
		my_strcpy.c	\
		my_strdup.c	\
		free_2darray.c	\
		my_itoa.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all: $(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
	cp my.h ../../include/

clean:
	rm -f $(NAME)
	rm -f *.o
	r -f lib/my/*.o

fclean: clean
	rm -f libmy.a
	rm -f ../libmy.a

re: fclean all

auteur:
	echo $(USER) > auteur

.PHONY: all clean fclean re auteur
