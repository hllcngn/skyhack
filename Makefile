NAME		= skyhack
CC		= /usr/bin/gcc
SRCFOLDER	= ./src/
SRCFILES	= \
		main.c \
		main2.c \
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
clean:
	rm -f skyhack.exe a.exe
	rm -f $(OBJ)
