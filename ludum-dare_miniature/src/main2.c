#include "INC.h"

void	game(Debug *db, Ui *ui, DUNGEON *dg){
char	c =0;
do {

//key input
switch(c){
case K_UI_DEBUG:
	if (db->on) undisplay_debug(db);
	else display_debug(db); break;
case K_UI_CONTROLS:
	if (ui->controls_on ==(int)'n') ui_display_controls(ui);
	else ui_undisplay_controls(ui); break;

case K_UP:
case K_DOWN:
case K_LEFT:
case K_RIGHT:
case K_UP_LEFT:
case K_UP_RIGHT:
case K_DOWN_LEFT:
case K_DOWN_RIGHT:
	break;
default: break;}

//display
display_lvl(5,15, dg->lvl[0]);//currlvl);
refresh();

//refresh ui
ui_refresh(ui);

} while ((c =getch()) !=K_QUIT);
return;}
