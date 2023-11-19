DSRC =	src/
SRC =	main.c \
	main2.c \
	ui.c \
	generate.c \
	EXTRA/rngbrush.c \
	EXTRA/c2buf.c \
	EXTRA/c2brush.c \
	draw.c \
	EXTRA/printbrush.c \
	display.c \
	EXTRA/debug.c
ALLSRC = $(addprefix $(DSRC),$(SRC))

DINC = inc/ \
       inc/EXTRA
ALLINC = $(addprefix -I,$(DINC))

all:
	gcc $(ALLSRC) $(ALLINC) -lncurses
