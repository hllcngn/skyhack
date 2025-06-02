NAME		= skyhack
CC		= /usr/bin/gcc
SRCFOLDER	= ./src/
SRCFILES	= \
		ncurses.c \
		main.c \
		main2.c \
		game.c \
		character.c \
		player.c \
		dungeon.c \
		floor.c \


OBJFOLDER	= ./obj/
OBJ		= $(addprefix $(OBJFOLDER), $(SRCFILES:.c=.o))
INCFOLDER	= ./inc/


all:	obj skyhack
obj:
	mkdir -p obj
skyhack:	$(OBJ)
	$(CC) $^ -o $(NAME) -lncurses
$(OBJFOLDER)%.o:	$(SRCFOLDER)%.c
	$(CC) -c $^ -o $@ -I$(INCFOLDER)

clean:
	rm -rf obj
fclean:	clean
	rm -f skyhack
re:	fclean all
