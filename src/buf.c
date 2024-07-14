#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

void save_buf(char* file, buf1 b){
FILE* f = fopen(file, "w");
char bufh[12]={0}, *p=bufh+11;
for (int n=b.h;n;n/=10) *p-- =n%10;
fwrite(bufh, 1, 12, f);		fputc('\n', f);
char bufw[12]={0};  p=bufw+11;
for (int n=b.w;n;n/=10) *p-- =n%10;
fwrite(bufw, 1, 12, f);		fputc('\n', f);
fwrite(b.c, 1, b.h*b.w, f);	fputc('\n', f);
fclose(f);}

void load_buf(FILE* f, buf1 *buf){
buf1 b = *buf;
char bu[12];
fread(bu, 1, 12, f);
for(int i=0;i<12;i++){
	b.h *= 10;
	b.h += bu[i];}		fgetc(f);
fread(bu, 1, 12, f);
for(int i=0;i<12;i++){
	b.w *= 10;
	b.w += bu[i];}		fgetc(f);
b.c = malloc(b.h*b.w);
fread(b.c, 1, b.h*b.w, f);
*buf = b;}
