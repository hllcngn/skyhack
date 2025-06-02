#include "h.h"
#include "myncurses.h"

int	main(int ac, char **av){
ncurses_init();

int re;

re= main2();

ncurses_end();
return re;
}
