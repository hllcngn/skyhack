1:
	gcc src/main1.c -lncurses -oogns

ludum-dare_miniature:
	gcc	previous-iterations/ludum-dare_miniature/src/main.c\
		previous-iterations/ludum-dare_miniature/src/main2.c\
		previous-iterations/ludum-dare_miniature/src/ui.c\
		previous-iterations/ludum-dare_miniature/src/generate.c\
		previous-iterations/ludum-dare_miniature/src/draw.c\
		previous-iterations/ludum-dare_miniature/src/display.c\
		previous-iterations/ludum-dare_miniature/src/EXTRA/rngbrush.c\
		previous-iterations/ludum-dare_miniature/src/EXTRA/c2buf.c\
		previous-iterations/ludum-dare_miniature/src/EXTRA/c2brush.c\
		previous-iterations/ludum-dare_miniature/src/EXTRA/printbrush.c\
		previous-iterations/ludum-dare_miniature/src/EXTRA/debug.c\
			-Iprevious-iterations/ludum-dare_miniature/inc\
			-Iprevious-iterations/ludum-dare_miniature/inc/EXTRA\
				-lncurses	-oludum-dare_miniature

iteration1:
	gcc	previous-iterations/iteration1/main.c \
		previous-iterations/iteration1/main2.c \
		previous-iterations/iteration1/generate.c \
		previous-iterations/iteration1/rngbrush.c \
		previous-iterations/iteration1/printbrush.c \
		previous-iterations/iteration1/draw.c \
		previous-iterations/iteration1/player_actions.c\
				-lncurses	-oiteration1

clean:
	rm	ogns.exe\
		ludum-dare_miniature.exe\
		iteration1.exe\
		*.stackdump

.PHONY:	ludum-dare_miniature iteration1
