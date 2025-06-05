#include "h.h"
#include "myncurses.h"

int	game(DUNGEON *dungeon, CHARACTER *player){
char c;
int q = 0;
int floorn = 0;

ncurses_display(dungeon->floor[floorn]);

while (!q){ c = getch(); switch (c){
// functioning
case 27: q = 1; break;

// movement
case 'w':
case 'a':
case 's':
case 'd':
case 'q':
case 'e':
case 'z':
case 'x':{vect v = get_move_vector(c);
	  character_movement(dungeon->floor[floorn], player, v);
	 } break;
case '>': if (dungeon->floor[floorn]->buf[player->y][player->x] == '>'){
		List *pl = list_pop(&dungeon->floor[floorn]->characters, player);
		floorn++;
		list_push_front(&dungeon->floor[floorn]->characters, pl);}
		break;
case '<': if (dungeon->floor[floorn]->buf[player->y][player->x] == '<'){
		List *pl = list_pop(&dungeon->floor[floorn]->characters, player);
		floorn--;
		list_push_front(&dungeon->floor[floorn]->characters, pl);}
		break;}

ncurses_display(dungeon->floor[floorn]);}

return EXIT_SUCCESS;}
