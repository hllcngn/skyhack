#ifndef MYNCURSES_H
#define MYNCURSES_H

#include <ncurses.h>

static WINDOW *uitop;
static WINDOW *uibot;
static WINDOW *gwin;

void	ncurses_init(void);
void	ncurses_end(void);
void	ncurses_uitop_refresh(void);
void	ncurses_uibot_refresh(void);
void	ncurses_game_refresh(FLOOR *floor);
void	ncurses_display(FLOOR *floor);

DUNGEON	*dungeon_new(void);
void	dungeon_free(DUNGEON *dungeon);
FLOOR	*floor_new(int floorn, int h, int w);
void	floor_free(FLOOR *floor);

#endif
