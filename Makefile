all:
	gcc -oOGNS \
		src/main.c \
		src/menu.c \
		src/menu_title.c \
		src/menu_new_game.c \
		src/menu_load_game.c \
		src/start_game.c \
		src/tools.c \
			-Isrc/inc \
			-lSDL2 -lSDL2_ttf -I. -L.
clean:
	rm *.exe*
