#include "h.h"

uint8_t*	seedc		= NULL;
unsigned int	seedui[8]	= {0};
int		seedn		= 0;


int randn(){
srand(seedui[seedn]);
seedui[seedn]++;
seedn++; if (seedn >=8) seedn =0;
return (rand());}


void rng_init(FILE* f){
load_seed(f);
srand(seedui[0]);}

void load_seed(FILE* f){
seedc = malloc(32);
fread(seedc, 1, 32, f);				fgetc(f);
char* buf =malloc(12);
for (int i =0; i <8; i++){
	fread(buf, 1, 12, f);
	seedui[i] = stoi(buf);			fgetc(f);}
free(buf);}

void make_states(){
uint8_t *p = (void*)seedui;
for (int i =0; i <8; i++)
	for (int j =0; j <4; j++)
		*(p +i*4 +j) = seedc[i*4 +j];}

void save_states(FILE* f){
fwrite(seedc, 1, 32, f);			fputc('\n', f);
for (int i =0; i <8; i++){
	fwrite(itos(seedui[i]), 1, 12, f);	fputc('\n', f);}}


void debug_seed(WINDOW* w){
wprintw(w, "\n rng states:\n");
/*
for (int i =0; i <8; i++){	//as numbers
	wprintw(w, "  %i\n", seedui[i]);}
*/
uint8_t *p = (void*)seedui;	//as letters
for (int i =0; i <8; i++){
	waddch(w, ' ');
	for (int j =0; j <4; j++){
		waddch(w, *(p +i*4 +j));}
	if (i%2) waddch(w, '\n');
	else	waddch(w, ' ');}}
