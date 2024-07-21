#include "h.h"

uint8_t* seedc	= NULL;
uint32_t seedui[8] = {0};
int seedn	= 0;


void rng_init(FILE* f){
load_seed(f);

srand(seedui[0]);}

int randn(){
srand(seedui[seedn]);
seedui[seedn]++;
seedn++; if (seedn >=8) seedn =0;
return (rand());}

void load_seed(FILE* f){
seedc = malloc(32);
fread(seedc, 1, 32, f);				fgetc(f);
char* buf =malloc(12);
for (int i =0; i <8; i++){
	fread(buf, 1, 12, f);			fgetc(f);
	seedui[i] = stoi(buf);
}
}

void save_states(FILE* f){
fwrite(seedc, 1, 32, f);			fputc('\n', f);
for (int i =0; i <8; i++){
	fwrite(itos(seedui[i]), 1, 12, f);	fputc('\n', f);}
}
