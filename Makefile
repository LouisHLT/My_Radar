##
## EPITECH PROJECT, 2022
## TEK1_22-23
## File description:
## Makefile
##

CC	=	gcc

SRC	=	src/my_str_to_word_array.c	\
		src/errors_handling.c	\
		src/parsing.c	\
		src/set_tower.c	\
		src/set_plane.c	\
		src/set_sprite.c	\
		src/make_clock.c	\
		src/my_getnbr.c	\
		src/display.c	\
		src/compute_entities.c	\

UT_SRC	=	src/my_str_to_word_array.c	\
			src/errors_handling.c	\
			lib/my/mini_printf.c	\
			lib/my/my_put_nbr.c	\
			lib/my/my_putchar.c	\
			lib/my/my_putstr.c	\
			lib/my/my_strcmp.c	\
			lib/my/my_strlen.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_radar

LDFLAGS	=	-L./lib/ -lmy

CPPFLAGS	=	-I./include

LIB	=	libmy.a

UT_NAME	=	unit_tests

CFLAGS	=	-g3 -Wall -Wextra

FUT	=	--coverage -lcriterion

UTFILES	=	tests/ut.h tests/make_map_from_string.c tests/tests_my_sokoban.c

all:	$(NAME)

$(NAME):	$(OBJ) $(LIB)
	gcc -o $(NAME) main.c $(SRC) $(LDFLAGS) $(CPPFLAGS) $(CFLAGS) -g3 \
	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm\
	 -Wall -Wextra

$(LIB):
	make -C lib/my/

tests_run:
	gcc -o $(UT_NAME) $(UT_SRC) $(UTFILES) $(LDFLAGS) $(CPPFLAGS) $(FUT)
	./$(UT_NAME)

debug:	CFLAGS += -g3
debug:	all

clean:
	rm -f $(NAME)
	rm -f *.o
	rm -f lib/my/*.o
	rm -f lib/my/libmy.a
	@echo -e "\e[1;32mCleaned\e[0m"

fclean: clean
	rm -f $(NAME)
	rm -f $(UT_NAME)
	rm -f *.gcno
	rm -f *.gcda
	rm -f lib/libmy.a
	rm -f src/*.o
	rm -f lib/my/*.o
	@find -name "vgcore.*" -delete
	@echo -e "\e[1;32mFcleaned\e[0m"

re: fclean all

auteur:
	echo $(USER) > auteur

.PHONY: all tests_run clean fclean re auteur
