#include "h.h"
#include "myncurses.h"

int	game(List *stack, DUNGEON *dungeon, CHARACTER *player, TIME *time){
char k;
int q = 0;
ncurses_display(time, dungeon);

while (!q){

k = getch(); switch (k){
case 27: q = 1; break; //TODO handle esc specifically

case 'w':
case 'a':
case 's':
case 'd':
case 'q':
case 'e':
case 'z':
case 'x': list_add(&stack, stack_new(1, player, &player_turn, (void*)&k));
	break;
case '>': // TODO put this on the stack too:
case '<': player_change_floor_stairs(dungeon, player, time, k); break;
default: time_add_s(time, 1); break;}


full_stack_do(&stack, time, dungeon);

ncurses_display(time, dungeon);
}

return EXIT_SUCCESS;}
