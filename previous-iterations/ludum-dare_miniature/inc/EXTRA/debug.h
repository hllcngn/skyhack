#ifndef DEBUG_H
#define DEBUG_H
#include <ncurses.h>

#define WDBGH LINES
#define WDBGW 35
#define WDBGY 0
#define WDBGX COLS-WDBGW

typedef struct{
	int	on;
	WINDOW	*w;
} Debug;

Debug	*debug_init(void);
void	debug_end(Debug*);

void	display_debug(Debug *db);
void	undisplay_debug(Debug *db);

void	debug_log(Debug*, const char*);

#endif
