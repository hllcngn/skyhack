#include "INC.h"

DUNGEON	*generate_dg(Debug *db){
DUNGEON	*dg =(DUNGEON*)malloc(sizeof(DUNGEON));
dg->lvl =(LEVEL**)malloc(NB_OF_FLOORS*sizeof(LEVEL*));

LEVEL *lvl; char c;
for (int i =0; i <NB_OF_FLOORS; i++)
{
//	dg->lvl[i] =generate_lvl(db, i);
//generate_lvl:
if (db->on) mvprintw(i+1,0, "- generating level no#%i... -", i);
lvl =(LEVEL*)malloc(sizeof(LEVEL));
lvl->id =i; lvl->nb =i+1;
lvl->map =alloc_c2buf(DGH,DGW);
if (db->on) mvprintw(i+2,0, "allocation successful");
//drawing random level
c2_fill(lvl->map, S_DFLT_FLOOR);
if (db->on) mvprintw(i+3,0, "c2_fill successful");
/*draw_random_wall(lvl);
draw_next_wall(lvl);
printw("\nrandom walls successful");*/

//if (db->on) display_lvl(lvl->nb+2,44, lvl);
//display_lvl:
display_outwall(lvl->nb+2,44);
//mvprintw(y-2+3,0, "display_outwall successful");
//flushinp();
getch();
//refresh();
c2_disp(lvl->map, lvl->nb+2,44);
//flushinp();
c = getch();
printw("c = %c", c);
c = getch();
printw("c = %c", c); getch();// because of getch call...
//refresh();
c2_disp(lvl->map, lvl->nb+2,45); getch();// <-- segv
//mvprintw(y-1+3,0, "c2_disp successful");

if (db->on) mvprintw(i+6,0, "level displayed");
//if (db->on) getch();
//refresh();
c2_disp(lvl->map, lvl->nb+21,75); getch();


mvprintw(20,75, "lvl nb#%i...",lvl->nb); getch();
addch(lvl->map->c[0]); getch();
c2_disp(lvl->map, 21,75); getch();
//display_lvl(22,75, dg->lvl[i]);	getch(); //debug

dg->lvl[i] =lvl;
mvprintw(14,75, "lvl nb#%i...",dg->lvl[i]->nb); getch();
addch(dg->lvl[i]->map->c[0]); getch();
c2_disp(dg->lvl[i]->map, 15,75); getch();
//display_lvl(16,75, dg->lvl[i]);	getch(); //debug
}
dg->currlvl =dg->lvl[0];
mvprintw(35,0,"\n\npress a key...");
mvprintw(35,0,"\nfyi: \'%c\' to quit", K_QUIT); getch(); erase();
return dg;}

LEVEL	*generate_lvl(Debug *db, int i){
if (db->on) mvprintw(i+1,0, "- generating level no#%i... -", i);
LEVEL	*lvl =(LEVEL*)malloc(sizeof(LEVEL));
lvl->id =i; lvl->nb =i+1;
lvl->map =alloc_c2buf(DGH,DGW);
if (db->on) mvprintw(i+2,0, "allocation successful");
//drawing random level
c2_fill(lvl->map, S_DFLT_FLOOR);
if (db->on) mvprintw(i+3,0, "c2_fill successful");
/*draw_random_wall(lvl);
draw_next_wall(lvl);
printw("\nrandom walls successful");*/
if (db->on) display_lvl(lvl->nb+2,44, lvl);
if (db->on) mvprintw(i+6,0, "level displayed");
if (db->on) getch();
return lvl;}

void	free_dg(DUNGEON *dg){
for (int i =0; i <NB_OF_FLOORS; i++){
	free_c2buf(dg->lvl[i]->map);
	free(dg->lvl[i]);}
free(dg->lvl);
free(dg); return;}
