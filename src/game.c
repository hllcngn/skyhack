#include "h.h"
#include "myncurses.h"

int	game(DUNGEON *dungeon, CHARACTER *player, TIME *time){
char c;
int q = 0;

ncurses_display(time, dungeon);

while (!q){

c = getch(); switch (c){
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
	  char furniture = character_movement(dungeon->currfloor, player, v);

	  //TODO pop this into its own function
	  if (furniture == '[' || furniture == ']' || furniture == 'I'){ // elevator doors
		int c2 = ncurses_prompt_call_elevator();
		if (c2 == 'y'){
			elevator_call(dungeon);
			time_add_s(time, 1);} break;}

	  if (player->currfloor == dungeon->floor[player->currfloor->floorn]
			&& (player->y == dungeon->elevator->floor->y+3
				&& player->x == dungeon->elevator->floor->x+2)
			&& (c == 'w' || c == 'q' || c == 'e')){ //TODO /!\ collisions
		player_change_floor(dungeon, dungeon->elevator->floor, player);}
	  else if (player->currfloor == dungeon->elevator->floor
			  &&(player->y == 3 && player->x == 2)
			  &&(c == 's' || c == 'z' || c == 'x')){
		player_change_floor(dungeon, dungeon->floor[dungeon->currfloor->floorn], player);}

	  time_add_s(time, 1);} break; //TODO increment only when moving
				       //or is it better to increment time no matter what
case '>':
case '<': player_change_floor_stairs(dungeon, player, time, c); break;}

ncurses_display(time, dungeon);}

return EXIT_SUCCESS;}
