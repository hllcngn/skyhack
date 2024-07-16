#include "h.h"

char* seed = NULL;


void rng_init(){
load_seed();
}

void load_seed(FILE* f){
seed = malloc(32);
fread(seed, 1, 32, f);
fgetc(f);}
