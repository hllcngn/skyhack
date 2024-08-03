#include "h.h"

uint8_t*	seedc		= NULL;
int		stateN		= 8;
uint32_t*	state		= NULL;
int		staten		= 0;

int	rn(int max){ //0-max inclusive
int	n;
/*
do { n =randn() /(RAND_MAX /max+1);
} while (n >max);
*/
n = randn()%(max+1);
return n;}
int	rrange(int min, int max){ //inclusive
int	n;
n =rn(max-min) +min;
return n;}


int randn(){
srand(state[staten]);
state[staten]++;
staten++; if (staten >=stateN) staten =0;
return (rand());}


void load_rng(FILE* f){
seedc = malloc(32);
fread(seedc, 1, 32, f);				fgetc(f);
for (int i =0; i <8; i++){
	fread(&(state[i]), 4, 1, f);		fgetc(f);}}

void save_rng(FILE* f){
fwrite(seedc, 1, 32, f);			fputc('\n', f);
for (int i =0; i <8; i++){
	fwrite(&(state[i]), 4, 1, f);		fputc('\n', f);}}


void debug_seed(WINDOW* w){
wprintw(w, "\n rng states:\n");
/*
for (int i =0; i <8; i++){	//as numbers
	wprintw(w, "  %i\n", seedui[i]);}
*/
/**/
uint8_t *p = (uint8_t*)state;	//as letters
wprintw(w, "%i\n", stateN);
for (int i =0; i <stateN; i++){
	waddch(w, ' ');
	for (int j =0; j <4; j++)
		waddch(w, p[i*4 +j]);
	if (i%2) waddch(w, '\n');
	else	 waddch(w, ' ');}
/**/
}
