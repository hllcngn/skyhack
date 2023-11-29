#include "ogns.h"

int*** genfloor(void){
int*** fl =(int***)malloc(sizeof(int**)*FLOOR_DEPTH);
for(int layer=0; layer<FLOOR_DEPTH; layer++)
	fl[layer] =(int**)malloc
