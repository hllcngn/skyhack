#include <stdio.h>
#include "struct.h"

void save_buf(char* file, buf1 b){
FILE* f = fopen(file, "w");
fwrite(b.c, 1, b.h*b.w, f);
fputc('\n', f);
fclose(f);}
