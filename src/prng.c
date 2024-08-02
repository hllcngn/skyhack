#include "h.h"

uint8_t*	seedc		= NULL;
uint32_t	states[8]	= {0};
int		seedn		= 0;

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
srand(states[seedn]);
states[seedn]++;
seedn++; if (seedn >=8) seedn =0;
return (rand());}


void load_rng(FILE* f){
seedc = malloc(32);
fread(seedc, 1, 32, f);				fgetc(f);
for (int i =0; i <8; i++){
	fread(&(states[i]), 1, 4, f);		fgetc(f);}}

void save_rng(FILE* f){
fwrite(seedc, 1, 32, f);			fputc('\n', f);
for (int i =0; i <8; i++){
	fwrite(&(states[i]), 1, 4, f);		fputc('\n', f);}}


void debug_seed(WINDOW* w){
wprintw(w, "\n rng states:\n");
/*
for (int i =0; i <8; i++){	//as numbers
	wprintw(w, "  %i\n", seedui[i]);}
*/
/**/
uint8_t *p = (uint8_t*)states;	//as letters
for (int i =0; i <8; i++){
	waddch(w, ' ');
	for (int j =0; j <4; j++)
		waddch(w, p[i*4 +j]);
	if (i%2) waddch(w, '\n');
	else	 waddch(w, ' ');}
/**/
}
