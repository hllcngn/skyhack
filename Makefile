CC	= /usr/bin/gcc
NAME	= skyhack
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

all:
	$(CC) $(SRC) -lncurses

clean:
	rm a.exe skyhack.exe
