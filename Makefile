all:
	gcc -oOGNS \
		src/main.c \
		src/menu_title.c \
		src/menu_new_game.c \
		src/tools_sdl.c \
			-Isrc/inc \
			-lSDL2 -lSDL2_ttf -I. -L.
clean:
	rm *.exe*
