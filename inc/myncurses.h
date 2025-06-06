#ifndef MYNCURSES_H
#define MYNCURSES_H
#include <ncurses.h>
#include "h.h"

static WINDOW *uitop;
static WINDOW *uibot;
static WINDOW *gwin;

void	ncurses_init(void);
void	ncurses_end(void);
int	ncurses_get_lines(void);
int	ncurses_get_cols(void);
void	ncurses_uitop_refresh(TIME* time, int floorn);
void	ncurses_uibot_refresh(void);
void	ncurses_game_refresh(FLOOR *floor);
void	ncurses_display(TIME *time, FLOOR *floor);

void	ncurses_draw_character(List *list);

#endif
