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
		c = ncurses_prompt_call_elevator();
		if (c == 'y')	elevator_call(dungeon);}

	  if (player->currfloor == dungeon->floor[player->currfloor->floorn]
			&& (player->y == dungeon->elevator->floor->y+3
				&& player->x == dungeon->elevator->floor->x+2)
			&& (c == 'w' || c == 'q' || c == 'e')){
		character_change_floor(dungeon->elevator->floor, player);
		dungeon->currfloor = dungeon->elevator->floor;}
	  else if (player->currfloor == dungeon->elevator->floor
			  &&(player->y == 3 && player->x == 2)
			  &&(c == 's' || c == 'z' || c == 'x')){
		character_change_floor(dungeon->floor[dungeon->currfloor->floorn], player);
		dungeon->currfloor = dungeon->floor[dungeon->currfloor->floorn];}

	  time_add_s(time, 1);} break;
case '>': if (dungeon->currfloor->buf[player->y][player->x] == '>'){
		character_change_floor(dungeon->floor[dungeon->currfloor->floorn+1], player);
		dungeon->currfloor = dungeon->floor[dungeon->currfloor->floorn+1];
		time_add_s(time, 30);} break;
case '<': if (dungeon->currfloor->buf[player->y][player->x] == '<'){
		character_change_floor(dungeon->floor[dungeon->currfloor->floorn-1], player);
		dungeon->currfloor = dungeon->floor[dungeon->currfloor->floorn-1];
		time_add_s(time, 30);} break;}

ncurses_display(time, dungeon);}

return EXIT_SUCCESS;}
