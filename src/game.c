#include "h.h"
#include "myncurses.h"

int	game(DUNGEON *dungeon){
int q = 1;
int floorn = 0;

while (q){

ncurses_display(dungeon->floor[floorn]);

getch();
q = 0;
}

return EXIT_SUCCESS;}
