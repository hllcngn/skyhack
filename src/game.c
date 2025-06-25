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
case 'x': list_add(&stack, stack_new(1, player, &player_movement, (void*)&k));
//	  vect v = get_move_vector(k);
//	  char hit = character_movement(dungeon->currfloor, player, v);
//	  elevator_handle_doorway(k, hit, dungeon, player);
//	  handle_hit(hit, dungeon); break;
break;
case '>':
case '<': player_change_floor_stairs(dungeon, player, time, k); break;}


full_stack_do(&stack, dungeon);

time_add_s(time, 1);//TODO increment only when moving
		    //or is it better to increment time no matter what
		    //i think it's nice to lose 1sec on an hesitation
		    //but it shouldn't be on top of other timed actions

ncurses_display(time, dungeon);
}

return EXIT_SUCCESS;}
