NAME		= skyhack
CC		= /usr/bin/gcc
SRCFOLDER	= ./src/
SRCFILES	= \
		main.c \
		main2.c \
		game.c \
		generate.c \
		rngbrush.c \
		printbrush.c \
		draw.c \
		player_actions.c \

OBJFOLDER	= ./obj/
OBJ		= $(addprefix $(OBJFOLDER), $(SRCFILES:.c=.o))
INCFOLDER	= ./inc/


all:	$(OBJ)
	$(CC) $^ -o $(NAME) -lncurses

$(OBJFOLDER)%.o:	$(SRCFOLDER)%.c
	$(CC) -c $^ -o $@ -I$(INCFOLDER)

hello:
	$(CC) ./src/hello.c -o hello -lncurses

clean:
	rm -f $(OBJ)
fclean:	clean
	rm -f skyhack.exe skyhack.exe.stackdump hello.exe
