#include "h.h"
#include "myncurses.h"

int	main2(void){
int re;
DUNGEON *dungeon;
CHARACTER *player;

dungeon = dungeon_new(ncurses_get_lines()-2, ncurses_get_cols());
player = character_new(dungeon->h/2, dungeon->w/2, 'G');
list_add(&(dungeon->floor[0]->characters), player);

re = game(dungeon);

dungeon_free(dungeon);
return re;}
