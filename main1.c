#include <ncurses.h>
#include "ogns.h"

int main(int ac, char** av){
initscr(); noecho(); cbreak();
curs_set(0);

printw("hey");

getch();
endwin();	return 0;}
