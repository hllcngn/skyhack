#ifndef CONST_H
#define CONST_H
#include <ncurses.h>

//dungeon
#define DGH 12 //outwalls non included
#define DGW 28
#define NB_OF_FLOORS 6

//character
#define STARTPOS_Y DGH-2
#define STARTPOS_X DGW/2

//UI
#define UI_CONTROLS_H 10
#define UI_CONTROLS_W 18
#define UI_CONTROLS_Y 2
#define UI_CONTROLS_X COLS -UI_CONTROLS_W -2

#endif
