#ifndef MYNCURSES_H
#define MYNCURSES_H
#include <ncurses.h>
#include "h.h"

static WINDOW *uitop;
static WINDOW *uibot;
static WINDOW *gwin;

int	ncurses_get_lines(void);
int	ncurses_get_cols(void);

void	ncurses_init(void);
void	ncurses_end(void);

void	ncurses_display(TIME *time, DUNGEON *dungeon);
void	ncurses_uitop_refresh(TIME* time, int floorn);
void	ncurses_uibot_refresh(void);
void	ncurses_floor_refresh(FLOOR *floor);
void	ncurses_draw_character(List *list);
char	ncurses_prompt_call_elevator(void);
int	ncurses_prompt_elevator_select(DUNGEON *dungeon);

#endif
