all:
	gcc -oOGNS \
		src/main.c \
			-Isrc \
			-lSDL2 -lSDL2_ttf -I. -L.
clean:
	rm *.exe*
