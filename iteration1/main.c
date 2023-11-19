#include "h.h"
#include <ncurses.h>
#include <stdlib.h>//rand
#include <time.h>//time()

int	main(int ac, char **av){
initscr();
curs_set(0); noecho(); cbreak();
//nodelay(stdscr, true);
//refresh();

srand((unsigned int)time(NULL));

//-> scanning argv
//
//c_player = the arg
//floor_type = NAND FLOOR_TYPE
//floor_type = 0 or 's' - FLOOR_TYPE
//if(FLOOR_TYPE+floor_type =='s')	//<=
//etc

// if(floor_type
// if(floor_type= etc
// else if )FLOOR+TYPE

printw("hello myskyscraper");
getch();
printw("\nthis is a somewhat goofy roguelike side-project");
getch();
printw("\nyour terminal is %i x %i, correct?", LINES, COLS);
getch();
printw("\nthe game will take up the whole window, continue?");
getch();

clear();
game();
clear();

clear();
printw("none of this would have been possible without darkmage");
getch();

endwin();
return 0;}
