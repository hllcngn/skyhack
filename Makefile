NAME	= skyhack
CC	= /usr/bin/gcc
SRCFOLDER	= ./src/
SRCFILES	= \
		main.c \
		main2.c \
		generate.c \
		rngbrush.c \
		printbrush.c \
		draw.c \
		player_actions.c
OBJFOLDER	= ./obj/
OBJFILES	= $(SRCFILES:.c=.o)
OBJ	= $(addprefix $(OBJFOLDER), $(OBJFILES))
#INCFOLDER	= ./src/

all:	$(OBJ)
	$(CC) $^ -o $(NAME) -lncurses
$(addprefix $(OBJFOLDER), %.o):	$(addprefix $(SRCFOLDER), %.c)
	$(CC) -c $^ -o $@ 
clean:
	rm -f skyhack.exe a.exe
	rm -f $(OBJ)
