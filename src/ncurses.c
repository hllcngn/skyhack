#include "myncurses.h"

void	ncurses_init(void){
initscr(); noecho(); cbreak();
curs_set(0); refresh();

uitop = newwin(1, COLS, 0, 0);
uibot = newwin(1, COLS, LINES-1, 0);
gwin = newwin(LINES-2, COLS, 1, 0);}

void	ncurses_end(void){
delwin(uitop);
delwin(uibot);
delwin(gwin);
endwin();}

int	ncurses_get_lines(void){return LINES;}
int	ncurses_get_cols(void){return COLS;}

void	ncurses_uitop_refresh(int floorn){
mvwprintw(uitop, 0, COLS-10, "Floor#%i", floorn+1);
wrefresh(uitop);}

void	ncurses_uibot_refresh(void){
mvwprintw(uibot, 0, 0, "ui bottom");
wrefresh(uibot);}

void	ncurses_game_refresh(FLOOR *floor){
wmove(gwin, 0, 0);
for (int i = 0; i < floor->h; i++)
	for (int j = 0; j < floor->w; j++)
		waddch(gwin, floor->buf[i][j]);
list_do(floor->characters, &ncurses_draw_character);
wrefresh(gwin);}

void	ncurses_draw_character(List *list){
mvwaddch(gwin,  ((CHARACTER*)(list->item))->y,
		((CHARACTER*)(list->item))->x,
		((CHARACTER*)(list->item))->c);}

void	ncurses_display(FLOOR *floor){
ncurses_uitop_refresh(floor->floorn);
ncurses_uibot_refresh();
ncurses_game_refresh(floor);}
