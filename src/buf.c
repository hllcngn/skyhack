#include "h.h"

void load_buf(FILE* f, buf1 *buf){
fread(&(buf->h), 1, 4, f);		fgetc(f);
fread(&(buf->w), 1, 4, f);		fgetc(f);
buf->c = malloc(buf->h*buf->w);
fread(buf->c, 1, buf->h*buf->w, f);	fgetc(f);}

void save_buf(FILE* f, buf1 b){
fwrite(&(b.h), 1, 4, f);		fputc('\n', f);
fwrite(&(b.w), 1, 4, f);		fputc('\n', f);
fwrite(b.c, 1, b.h*b.w, f);		fputc('\n', f);}

void debug_buf(WINDOW* w, buf1 b){
wprintw(w, "\n h: %i  w: %i\n", b.h, b.w);}
