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
SRC	= $(addprefix $(SRCFOLDER), $(SRCFILES))
OBJ	= $(SRC:.c=.o)
#INCFOLDER	= ./src/

all:	$(OBJ)
	$(CC) $^ -o $(NAME) -lncurses
%.o:	%.c
	$(CC) -c $^ -o $@ 
clean:
	rm -f skyhack.exe a.exe
	rm -f $(OBJ)
