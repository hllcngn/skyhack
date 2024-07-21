#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

char* itos(unsigned int i){
char *buf=calloc(12, 1), *p=buf+11;
for (int n=i;n;n/=10) *p-- =n%10;
return buf;}

unsigned int stoi(char* buf){
unsigned int i = 0;
for (int n =0; n <12; n++){
	i *= 10;
	i += buf[11-n];}
return i;}


void save_buf(FILE* f, buf1 b){
//FILE* f = fopen(file, "r+");
//fseek(f, 33, SEEK_SET);
//char bufh[12]={0}, *p=bufh+11;
//for (int n=b.h;n;n/=10) *p-- =n%10;
fwrite(itos(b.h), 1, 12, f);		fputc('\n', f);
//char bufw[12]={0};  p=bufw+11;
//for (int n=b.w;n;n/=10) *p-- =n%10;
fwrite(itos(b.w), 1, 12, f);		fputc('\n', f);
fwrite(b.c, 1, b.h*b.w, f);		fputc('\n', f);
//fclose(f);
}

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
