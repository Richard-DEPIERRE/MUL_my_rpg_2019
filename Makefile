##
## EPITECH PROJECT, 2019
## makefile infin_add
## File description:
## compile lib etc
##

CC		=	gcc

CFLAGS	=	--coverage -lcriterion -I./include

SRC	=	src/clics_handlings.c	\
		src/clock_event.c		\
		src/draw_statue.c		\
		src/global_event.c		\
		src/init_player.c		\
		src/main_rpg.c			\
		src/main.c				\
		src/menu.c				\
		src/mouse_clic_s_0.c	\
		src/my_putstr.c			\
		src/my_strlen.c			\
		src/options.c			\
		src/player_rects.c

SRC2 =	tests/test_main.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

NAME2	=	units

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -W -Wall -Wextra -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system -g3 -I./include
	rm -f $(OBJ)
clean:
	rm -f $(OBJ)
fclean:	clean
	rm -f $(NAME)
	rm -f $(NAME2)
	rm -f *.gcda *.gcno *.info

re:	fclean all

tests_run:
	$(CC) -o $(NAME2) $(SRC2) $(CFLAGS)
	./$(NAME2)