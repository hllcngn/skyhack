#include "h.h"

void save_buf(FILE* f, buf1 b){
fwrite(itos(b.h), 1, 12, f);		fputc('\n', f);
fwrite(itos(b.w), 1, 12, f);		fputc('\n', f);
fwrite(b.c, 1, b.h*b.w, f);		fputc('\n', f);}

void load_buf(FILE* f, buf1 *buf){
buf1 b = *buf;
char bu[12];
fread(bu, 1, 12, f);
b.h = stoi(bu);			fgetc(f);
fread(bu, 1, 12, f);
b.w = stoi(bu);			fgetc(f);
b.c = malloc(b.h*b.w);
fread(b.c, 1, b.h*b.w, f);	fgetc(f);
*buf = b;}

void debug_buf(WINDOW* w, buf1 b){
wprintw(w,  "\n h: %i  w: %i\n", b.h, b.w);}
