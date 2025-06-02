#include "h.h"
#include "myncurses.h"

int	main2(void){

int re;
DUNGEON *dungeon;

dungeon = dungeon_new();
re = game(dungeon);

dungeon_free(dungeon);
return re;
}
