ludum-dare_miniature:
	gcc	ludum-dare_miniature/src/main.c\
		ludum-dare_miniature/src/main2.c\
		ludum-dare_miniature/src/ui.c\
		ludum-dare_miniature/src/generate.c\
		ludum-dare_miniature/src/draw.c\
		ludum-dare_miniature/src/display.c\
		ludum-dare_miniature/src/EXTRA/rngbrush.c\
		ludum-dare_miniature/src/EXTRA/c2buf.c\
		ludum-dare_miniature/src/EXTRA/c2brush.c\
		ludum-dare_miniature/src/EXTRA/printbrush.c\
		ludum-dare_miniature/src/EXTRA/debug.c\
			-Iludum-dare_miniature/inc\
			-Iludum-dare_miniature/inc/EXTRA\
				-lncurses	-oludum-dare_miniature

iteration1:
	gcc	iteration1/main.c \
		iteration1/main2.c \
		iteration1/generate.c \
		iteration1/rngbrush.c \
		iteration1/printbrush.c \
		iteration1/draw.c \
		iteration1/player_actions.c	-lncurses	-oiteration1

clean:
	rm	ludum-dare_miniature.exe\
		iteration1.exe\
		*.stackdump

.PHONY:	ludum-dare_miniature iteration1
