#include "h.h"

int	main(int ac, char **av){
initscr();
curs_set(0); noecho(); cbreak();
refresh();

//if (title()==-1){ endwin(); return 0; }

int new_player = 0;
if (access("saves/save1", F_OK)){	//new game funct?
	//seed_selection();
/**/	seedc = malloc(32);	//debug
	strcpy(seedc,"#@@vhtttjudasmmmmhhgtyzgggp;;;;;");	/**/
	memcpy(states, seedc, 32);	//making states
	new_player = 1;}

//loading player settings
PLAYER_SETTINGS* ps = malloc(sizeof(PLAYER_SETTINGS)); ps->saving = 'a';

int quit = 0, menu = 1;
while (menu && !quit){ switch (main_menu()){
case 'p':	menu = 0;			break;
case 's':	if (settings(ps))  quit++;	break;
case 'q':	quit++;				break;}}

if (!quit){
GAME* gm =calloc(sizeof(GAME),1);
main2(gm, new_player);

free(seedc);
free(gm);}

//printw("none of this would have been possible without darkmage"); getch();
endwin();
return 0;}



int title(){
char c; clear();
printw("hello myskyscraper");
c= getch();	if(c== 'q')			return -1;
		else if(c== 27)			return 0;
printw("\nthis is a somewhat goofy roguelike side-project");
c= getch();	if(c== 'q')			return -1;
		else if(c== 27)			return 0;
printw("\nyour terminal is %i x %i, correct?", LINES, COLS);
c= getch();	if(c== 'q' || c== 'n')		return -1;
		else if(c== 27)			return 0;
printw("\nthe game will take up the whole window, continue?");
c= getch();	if(c==27 || c== 'q' || c=='n')	return -1;
return 0;}

void seed_selection(){
int i = 0; char c; char* sd = malloc(32); clear();
printw("seed selection");
printw("\nLooks like it's your first time playing skyhack!");
getch();
printw("\nLet's create your personal seed");
printw("\nskyhack seeds are 32 characters in length");
printw("\ncharacters can be any printable ASCII character, or space");
getch();
printw("\nPlease decide on your first character:");
printw("\n> ");
while((c=getch())<32 || c>126); addch(c); sd[i] = c; i++;
printw("\nchoose a couple additional impactful characters:");
printw("\n> ");
while((c=getch())<32 || c>126); addch(c); sd[i] = c; i++;
while((c=getch())<32 || c>126); addch(c); sd[i] = c; i++;
for (int j =0; j <5; j++){
	printw("\ndecide on the next 5 characters:");
	printw("\n> ");
	while((c=getch())<32 || c>126); addch(c); sd[i] = c; i++;
	while((c=getch())<32 || c>126); addch(c); sd[i] = c; i++;
	while((c=getch())<32 || c>126); addch(c); sd[i] = c; i++;
	while((c=getch())<32 || c>126); addch(c); sd[i] = c; i++;
	while((c=getch())<32 || c>126); addch(c); sd[i] = c; i++;}
printw("\nfinish off strong with an extra 4 characters:");
printw("\n> ");
while((c=getch())<32 || c>126); addch(c); sd[i] = c; i++;
while((c=getch())<32 || c>126); addch(c); sd[i] = c; i++;
while((c=getch())<32 || c>126); addch(c); sd[i] = c; i++;
while((c=getch())<32 || c>126); addch(c); sd[i] = c; i++;
printw("\nYour personal seed: %s",sd);
printw("\npress a key to continue...");		getch();

FILE* f = fopen("saves/save1","w");
fwrite(sd, 1, 32, f); fputc('\n', f);
fclose(f);
seedc = realloc(sd, 32);}

int main_menu(){
clear();
printw("\tMAIN MENU\n\n");
printw("o Play (p)\n");
printw("o Settings (s)\n");
printw("o Quit (q)\n");
char c;
while((c=getch())!='p' && c!='s' && c!='q');
return c;}

int settings(PLAYER_SETTINGS* ps){
char c; int menu = 1; clear();
printw("\t SETTINGS\n\n");
printw("Autosave (a)\n");
printw("Player save (p)\n");
printw("\nback - ESC");
while (1) {
while((c=getch())!='q' && c!='a' && c!='p' && c!=27); switch(c){
case 'q':	return -1;
case 27:	return 0;
case 'a':	ps->saving = c;	break;
case 'p':	ps->saving = c;	break;}}
return 0;}
