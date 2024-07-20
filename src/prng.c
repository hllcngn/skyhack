#include "h.h"

uint8_t* seedc = NULL;
uint32_t seedui[8] = {0};


void rng_init(){
load_seed();

//because this process would change if sizeof(types) changed
//from byte-to-byte opearation
//and it would segv
for (int i =0; i <8; i++)
	for (int j =0; j <4; j++)
		*(uint8_t*)(seedui +i*4 +j) = seedc[i*4 +j];
srand(seedui[0]);
}

void load_seed(FILE* f){
seedc = malloc(32);
fread(seedc, 1, 32, f);
fgetc(f);}

int randn(){
return (rand());
}
