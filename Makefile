##
## EPITECH PROJECT, 2019
## makefile infin_add
## File description:
## compile lib etc
##

CC		=	gcc

CFLAGS	=	-W -Wall -Wextra -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system -g3 -I./include -lm

SRC	=	src/clics_handlings.c		\
		src/clock_event.c			\
		src/draw_statue.c			\
		src/global_event.c			\
		src/init_player.c			\
		src/main_rpg.c				\
		src/main.c					\
		src/mouse_clic_s_0.c		\
		src/my_putstr.c				\
		src/my_strlen.c				\
		src/options.c				\
		src/player_rects.c			\
		src/save.c			\
		src/menu/check_mouse.c		\
		src/menu/check_mouse2.c		\
		src/menu/click_menu.c		\
		src/menu/draw_menu.c		\
		src/menu/menu_destroy.c		\
		src/menu/menu_set_sprites.c	\
		src/menu/menu_set2.c		\
		src/menu/particules.c		\
		src/menu/click_menu2.c		\
		src/get_next_char.c			\
		src/load_map.c				\
		src/create_perspective.c	\
		src/tuto/draw_tuto.c		\
		src/tuto/tuto.c				\

SRC2 =	tests/test_main.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

NAME2	=	units

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)
fclean:	clean
	rm -f $(NAME)
	rm -f $(NAME2)
	rm -f *.gcda *.gcno *.info

re:	fclean all

tests_run:
	$(CC) -o $(NAME2) $(SRC2) --coverage -lcriterion -I./include
	./$(NAME2)