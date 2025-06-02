#include "h.h"
#include "myncurses.h"

void	ncurses_init(void){
initscr(); noecho(); cbreak();
curs_set(0); refresh();

uitop = newwin(1, COLS, 0, 0);
uibot = newwin(1, COLS, LINES-1, 0);
gwin = newwin(LINES-2, COLS, 1, 0);
}

void	ncurses_end(void){
delwin(uitop);
delwin(uibot);
delwin(gwin);
endwin();
}

void	ncurses_uitop_refresh(void){
mvwprintw(uitop, 0, 0, "hello");
wrefresh(uitop);
}

void	ncurses_uibot_refresh(void){
mvwprintw(uibot, 0, 0, "bottom");
wrefresh(uibot);
}

void	ncurses_game_refresh(FLOOR *floor){
wmove(gwin, 0, 0);
for (int i = 0; i < floor->h; i++)
	for (int j = 0; j < floor->w; j++)
		waddch(gwin, floor->buf[i][j]);
wrefresh(gwin);
}

void	ncurses_display(FLOOR *floor){
ncurses_uitop_refresh();
ncurses_uibot_refresh();
ncurses_game_refresh(floor);
}
