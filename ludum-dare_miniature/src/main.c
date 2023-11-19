#include "INC.h"

int title(void);

int	main(int ac, char **av){
initscr(); noecho(); cbreak();
curs_set(0); //nodelay(stdscr, true);
rng_init();

Debug	*db =debug_init();
{int i; if ((i =title())==-1){ endwin(); return i;}
erase(); refresh();
if (i =='d') display_debug(db);}

debug_log(db, "creating ui...");		Ui *ui =ui_create();
debug_log(db, "generating player struct...");
PLAYER	player;
//class selection HERE
debug_log(db, "generating score struct...");
SCORE	score;
score.total	=0;
score.ennemies_killed	=0;
debug_log(db, "generating character struct...");
CHARACTER	ch4r;
ch4r.symbol	=S_CHARACTER;
ch4r.pos	=(vect){STARTPOS_Y,STARTPOS_X};
debug_log(db, "-- dungeon generation --");	DUNGEON *dg =generate_dg(db);
debug_log(db, "dungeon generation successful");
//entities generation
//HERE

debug_log(db, "launching game loop...");	game(db, ui, dg);
debug_log(db, "exit game loop");

	erase();
	printw("SCORE SCREEN HERE");
	printw("\n total score : %i", score.total);
	//credits HERE
	printw("\n\npress a key..."); getch();

debug_log(db, "-- cleanup --");
debug_log(db, "freeing dungeon...");		free_dg(dg);
debug_log(db, "freeing ui...");			ui_free(ui);
debug_log(db, "cleanup successful");
debug_end(db);
endwin(); return 0;}



int title(void){
printw("Hello Ludum Dare!\n");
printw("\nWelcome to the mini version of a roguelike I've been working on.");
printw("\nOf Glass And Steel - a skyscraper roguelike\n");
printw("\nyour terminal is %i x %i.", LINES, COLS);
if (LINES <DGH+2 || COLS <DGW+2){
	printw("\nbut it needs to be at least %i x %i for the game",
					DGH+2,DGW+2);
	getch(); return -1;}
printw("\nvalid size");
printw("\n\npress a key..."); return getch();}
