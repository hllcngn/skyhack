#include "h.h"
#include "myncurses.h"

int	main2(void){
int re;
TIME *time;
DUNGEON *dungeon;
CHARACTER *player;

dungeon = dungeon_new(ncurses_get_lines()-2, ncurses_get_cols());
player = character_new(dungeon->h/2, dungeon->w/2, 0, dungeon->currfloor, 'G');
list_add(&(dungeon->floor[0]->characters), player);

time = malloc(sizeof(TIME));
time->h = time->m = time->s = time->d = 0;

re = game(dungeon, player, time);

free(time);
dungeon_free(dungeon);
return re;}
