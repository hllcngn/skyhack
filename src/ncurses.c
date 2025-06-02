#include "h.h"
#include "myncurses.h"
void	ncurses_init(void){
initscr(); noecho(); cbreak();
curs_set(0); refresh();
}

void	ncurses_end(void){
endwin();
}
