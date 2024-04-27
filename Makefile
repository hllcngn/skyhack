all:
	gcc -oOGNS \
		src/main.c \
		src/menu_title.c \
		src/tools_sdl.c \
			-Isrc \
			-lSDL2 -lSDL2_ttf -I. -L.
clean:
	rm *.exe*
