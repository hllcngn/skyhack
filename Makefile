all:
	gcc -oOGNS \
		src/main.c \
			-lSDL2 -I. -L.
clean:
	rm *.exe*
