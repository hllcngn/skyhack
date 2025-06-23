#include "myncurses.h"
int	ncurses_get_lines(void){return LINES;}
int	ncurses_get_cols(void){return COLS;}


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


void	ncurses_display(TIME *time, DUNGEON *dungeon){
ncurses_uitop_refresh(time, dungeon->currfloor->floorn);
ncurses_uibot_refresh();
if (dungeon->currfloor != dungeon->elevator->floor
		|| dungeon->elevator->door_open == 1)
	ncurses_floor_refresh(dungeon->floor[dungeon->currfloor->floorn]);
if (dungeon->currfloor != dungeon->elevator->floor
		&& dungeon->elevator->floor->floorn == dungeon->currfloor->floorn
		&& dungeon->elevator->door_open == 1)
	ncurses_floor_refresh(dungeon->elevator->floor);
if (dungeon->currfloor == dungeon->elevator->floor)
	ncurses_floor_refresh(dungeon->elevator->floor);}

void	ncurses_uitop_refresh(TIME *time, int floorn){
mvwprintw(uitop, 0, COLS-12-10, "Floor#%i", floorn+1);
mvwprintw(uitop, 0, COLS-12, "%3i:%2i:%2i:%2i",
		time->d, time->h, time->m, time->s);
wrefresh(uitop);}

void	ncurses_uibot_refresh(void){
mvwprintw(uibot, 0, 0, "nothing there yet");
wrefresh(uibot);}

void	ncurses_floor_refresh(FLOOR *floor){
for (int i = 0; i < floor->h; i++){
	wmove(gwin, floor->y+i, floor->x);
	for (int j = 0; j < floor->w; j++)
		waddch(gwin, floor->buf[i][j]);}
list_do(floor->characters, &ncurses_draw_character);
wrefresh(gwin);}

void	ncurses_draw_character(List *list){
mvwaddch(gwin,  ((CHARACTER*)(list->item))->currfloor->y+((CHARACTER*)(list->item))->y,
		((CHARACTER*)(list->item))->currfloor->x+((CHARACTER*)(list->item))->x,
		((CHARACTER*)(list->item))->c);}


char	ncurses_prompt_call_elevator(void){
WINDOW *elevwin = newwin(5, 20, (LINES-5)/2, (COLS-20)/2);
mvwprintw(elevwin, 2, (20-13)/2, "call elevator?");
mvwprintw(elevwin, 3, (20-3)/2, "y/n");
wrefresh(elevwin);
delwin(elevwin);
return getch();}
