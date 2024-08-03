#include "h.h"

int	main(int ac, char **av){
initscr();
curs_set(0); noecho(); cbreak();
refresh();
//if (title()==-1){ endwin(); return 0; }

//seed creation for new players
int new_player = 0;
if (access("saves/save1", F_OK)){	//new game funct?
	//seed_selection();
	state = malloc(4*8); //must be initialized in case mood
/**/	seedc = malloc(32);	//debug
	strcpy(seedc,"#@@vhtttjudasmmmmhhgtyzgggp;;;;;");	/**/
	memcpy(state, seedc, 32);	//making states
	new_player = 1;}

//loading player settings
PLAYER_SETTINGS* ps = malloc(sizeof(PLAYER_SETTINGS));
if (access("saves/settings", F_OK)){
	ps->saving = 'a';
	ps->mood = '0';
	save_settings(ps);}
else	load_settings(ps);

//main menu
int quit = 0;/*, menu = 1;
while (menu && !quit){ switch (main_menu()){
case 'p':	menu = 0;			break;
case 's':	if (settings(ps))  quit++;	break;
case 'q':	quit++;				break;}}*/
if (!quit){

//mood setting
if (ps->mood == '1')
	mood_setting();

//game launch
GAME* gm =calloc(sizeof(GAME),1);
main2(gm, ps, new_player);

free(seedc);
free(ps);
free(gm);}
//printw("none of this would have been possible without darkmage"); getch();
endwin();
return 0;}



int title(){
char c; erase();
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
int i = 0; char c; char* sd = malloc(32); erase();
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
erase();
printw("\tMAIN MENU\n\n");
printw("o Play (p)\n");
printw("o Settings (s)\n");
printw("o Quit (q)\n");
char c;
while((c=getch())!='p' && c!='s' && c!='q');
return c;}

int settings(PLAYER_SETTINGS* ps){
char c; int menu = 1; erase();
printw("\t SETTINGS\n\n");
printw("Autosave (a) - Player save (p)\n");
printw("Mood - off (0) - on (1)\n");
int quit = 0; while (!quit){
while((c=getch())!=27	&& c!='a' && c!='p'
			&& c!='0' && c!='1');
switch(c){
case 27:	quit++;		break;
case 'a':	ps->saving = c;	break;
case 'p':	ps->saving = c;	break;
case '0':	ps->mood = c;	break;
case '1':	ps->mood = c;	break;}}
save_settings(ps);
return 0;}

void save_settings(PLAYER_SETTINGS* ps){
FILE* f = fopen("saves/settings", "w");
fwrite(&(ps->saving), 1, 1, f);	fputc('\n', f);
fwrite(&(ps->mood), 1, 1, f);	fputc('\n', f);
fclose(f);}
void load_settings(PLAYER_SETTINGS* ps){
FILE* f = fopen("saves/settings", "r");
fread(&(ps->saving), 1, 1, f);	fgetc(f);
fread(&(ps->mood), 1, 1, f);	fgetc(f);
fclose(f);}

void mood_setting(){
stateN = 9;
state = realloc(state, 4*9);
erase();
printw("- you're seeing this screen because you've enabled moody prng -\n");
printw("\nPlease select your present mood in within 4 characters:\n");
printw("> ");
char c; int i = 0; uint8_t j[4];
while((c=getch())<32 || c>126); addch(c); j[i] = c; i++;
while((c=getch())<32 || c>126); addch(c); j[i] = c; i++;
while((c=getch())<32 || c>126); addch(c); j[i] = c; i++;
while((c=getch())<32 || c>126); addch(c); j[i] = c; i++;
memcpy(&(state[8]), j, 4);
printw("\n\npress a key to continue...");		getch();}
