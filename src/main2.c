#include "h.h"
#include "myncurses.h"

int	main2(void){
int re;
TIME *time;
List *stack;
DUNGEON *dungeon;
CHARACTER *player;

time = malloc(sizeof(TIME));
 time->h = time->m = time->s = time->d = 0;
stack = NULL;
dungeon = dungeon_new(ncurses_get_lines()-2, ncurses_get_cols());
player = character_new(dungeon->h/2, dungeon->w/2, dungeon->floor[0], 'G');
 list_add(&(dungeon->floor[0]->characters), player);

re = game(stack, dungeon, player, time);
//TODO saving

//stack_free(stack);
free(time);
dungeon_free(dungeon);
return re;}
