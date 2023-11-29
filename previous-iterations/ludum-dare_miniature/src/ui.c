#include "INC.h"

Ui	*ui_create(void){
Ui	*ui =(Ui*)malloc(sizeof(Ui));
ui->w_controls =newwin(UI_CONTROLS_H,UI_CONTROLS_W,
		UI_CONTROLS_Y,UI_CONTROLS_X);
ui->controls_on =(int)'n';
return ui;}

void	ui_free(Ui *ui){
delwin(ui->w_controls);
free(ui); return;}

void	ui_refresh(Ui *ui){
if (ui->controls_on ==(int)'y') wrefresh(ui->w_controls);
return;}

void	ui_draw_controls(WINDOW *w){
box(w, 0,0);
mvwprintw(w, 1,UI_CONTROLS_W/2-4, "Controls");
mvwprintw(w, 2,UI_CONTROLS_W/2-2, "----");
mvwprintw(w, 3,2, "0 - quit");
mvwprintw(w, 4,2, "wasdqezx - movement");
return;}

void	ui_display_controls(Ui *ui){
ui->controls_on =(int)'y';
ui_draw_controls(ui->w_controls); wrefresh(ui->w_controls); return;}
void	ui_undisplay_controls(Ui *ui){
ui->controls_on =(int)'n';
werase(ui->w_controls); wrefresh(ui->w_controls); return;}
