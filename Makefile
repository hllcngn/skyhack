all:
	gcc -oOGNS \
		src/main.c \
		src/menu.c \
		src/start_game.c \
		src/tools.c \
		src/menus/menu_title.c \
		src/menus/menu_new_game.c \
		src/menus/menu_load_game.c \
			-Isrc/inc \
			-lSDL2 -lSDL2_ttf -I. -L.
clean:
	rm *.exe*
