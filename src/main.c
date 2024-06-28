#include "h.h"

int	main(int ac, char **av){
initscr();
curs_set(0); noecho(); cbreak();
refresh();
srand(time(NULL));
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

//if(title()==-1){ endwin(); return 0; }

GAME* gam= calloc(sizeof(GAME),1);
main2(gam);

//printw("none of this would have been possible without darkmage"); getch();
free(gam);
endwin();
return 0;}



int title(){
char c;
clear();
printw("hello myskyscraper");
c= getch();	if(c== 'q') return -1;
		else if(c== 27) return 0;
printw("\nthis is a somewhat goofy roguelike side-project");
c= getch();	if(c== 'q') return -1;
		else if(c== 27) return 0;
printw("\nyour terminal is %i x %i, correct?", LINES, COLS);
c= getch();	if(c== 'q' || c== 'n') return -1;
		else if(c== 27) return 0;
printw("\nthe game will take up the whole window, continue?");
c= getch();	if(c==27 || c== 'q' || c=='n') return -1;
return 0;}
