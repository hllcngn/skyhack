#include "h.h"


int	main(int ac, char **av){
srand(time(NULL));
initscr();
curs_set(0); noecho(); cbreak();
refresh();

//if(title()==-1){ endwin(); return 0; }

GAME* gm= calloc(sizeof(GAME),1);
main2(gm);
free(gm);

//printw("none of this would have been possible without darkmage"); getch();
endwin();
return 0;}




int title(){
char c;  clear();
printw("hello myskyscraper");
c= getch();	if(c== 'q')	return -1;
		else if(c== 27)	return 0;
printw("\nthis is a somewhat goofy roguelike side-project");
c= getch();	if(c== 'q')	return -1;
		else if(c== 27)	return 0;
printw("\nyour terminal is %i x %i, correct?", LINES, COLS);
c= getch();	if(c== 'q' || c== 'n')	return -1;
		else if(c== 27)		return 0;
printw("\nthe game will take up the whole window, continue?");
c= getch();	if(c==27 || c== 'q' || c=='n') return -1;
return 0;}
