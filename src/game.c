#include "h.h"

int	game(GAME* gm, PLAYER_SETTINGS* ps){
vect	pos =	gm->pos;
char*	clsn=	gm->clsn;
buf1	b1  =	gm->b1;
WINDOW* wd  =	newwin(10, 15, 0,COLS-15);

char k= 0; while(k= getch()){
	switch(k){
case ']':	//draw a random room
	make_level(clsn, b1);		break;
case '\\':	//debug
	werase(wd);
	debug_buf(wd, b1);
	debug_seed(wd);
	wrefresh(wd);			break;

case K_MENU:	//game menu
	//return 0;
/**/	int quit = 0, menu = 1;
	while (menu){ switch (game_menu(ps)){
	case 27:	menu = 0;			break;
	case 'a':	save_game(gm); 			break;
	case 's':	if (settings(ps))  return 0;	break;
	case 'q':	return 0;			break;}}
	draw_level(clsn, b1);
	mvaddch(pos.y,pos.x, C_PLAYER);		/**/

case K_UP:
case K_DOWN:
case K_LEFT:
case K_RIGHT:
case K_UP_LEFT:
case K_UP_RIGHT:
case K_DOWN_LEFT:
case K_DOWN_RIGHT:
	//character & floor tile are redrawn inside of this function
	player_move(k, &pos, clsn);	break;
default:				break;}}
return 0;}

int game_menu(PLAYER_SETTINGS* ps){
erase();
printw("\tMENU\n\n");
if (ps->saving == 'p') printw("o sAve (a)\n");
printw("o Settings (s)\n");
printw("o Quit (q)\n");
char c;
while((c=getch())!='a' && c!='s' && c!='q' && c!=27);
return c;}
