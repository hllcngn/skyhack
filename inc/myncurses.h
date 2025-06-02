#ifndef MYNCURSES_H
#define MYNCURSES_H

#include <ncurses.h>

static WINDOW *uitop;
static WINDOW *uibot;
static WINDOW *gwin;

void	ncurses_init(void);
void	ncurses_end(void);

#endif
