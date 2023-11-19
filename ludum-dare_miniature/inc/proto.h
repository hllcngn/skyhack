#ifndef PROTOTYPES_H
#define PROTOTYPES_H
#include "obj.h"

#include "EXTRA/rngbrush.h"
#include "EXTRA/printbrush.h"
#include "EXTRA/debug.h"
#include "EXTRA/c2buf.h"

void	game(Debug *db, Ui *ui, DUNGEON *dg);

// generate.c
DUNGEON	*generate_dg(Debug *db);
LEVEL	*generate_lvl(Debug *db, int i);
void	free_dg(DUNGEON *dg);
// rngbrush.c
// -> see rngbrush.h

// draw.c
void	draw_enclosing_walls(LEVEL *lvl);
void	draw_random_wall(LEVEL *lvl);
void	draw_rand_vert_wall(LEVEL *lvl);
void	draw_rand_hor_wall(LEVEL *lvl);
void	draw_next_wall(LEVEL *lvl);
// see c2brush

// display.c
void	display_lvl(int y,int x, LEVEL *lvl);
void	display_outwall(int y,int x);
// printbrush.c
// -> see printbrush.h

// ui.c
Ui	*ui_create(void);
void	ui_free(Ui *ui);
void	ui_refresh(Ui *ui);
void	ui_display_controls(Ui *ui);
void	ui_undisplay_controls(Ui *ui);
// debug.c
// -> see debug.h
#endif
