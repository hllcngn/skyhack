#include "c2buf.h"

void c2_line(c2buf *buf, int y){
c2_stroke(buf, y,0, buf->w, '-'); return;}
void c2_vline(c2buf *buf, int x){
c2_vstroke(buf, 0,x, buf->h, '|'); return;}

void c2_stroke(c2buf *buf, int y,int x, int n, char c){
char *p =buf->l[y]+x; //todo: stroke() over multiple lines
if (n >0) for (int i=0; i<n && p[i]; i++){ p[i] =c;}
else	  for (int i=0; i>n && p[i]; i--){ p[i] =c;} return;}
void c2_vstroke(c2buf *buf, int y,int x, int n, char c){
char **l =buf->l +y*sizeof(char*);
if (n >0) for (int i=0; i<n && l[i][x]; i++){ l[i][x] =c;}
else	  for (int i=0; i>n && l[i][x]; i--){ l[i][x] =c;} return;}

void c2_stroketil(c2buf *buf, int y,int x, int n, char c, char X){
char *p =buf->l[y]+x;
if (n >0) for (int i=0; i<n && p[i] && p[i]!=X; i++){ p[i] =c;}
else	  for (int i=0; i>n && p[i] && p[i]!=X; i--){ p[i] =c;} return;}
void c2_vstroketil(c2buf *buf, int y,int x, int n, char c, char X){
char **l =buf->l +y*sizeof(char*);
if (n >0) for (int i=0; i<n &&l[i][x] &&l[i][x]!=X; i++){ l[i][x]=c;}
else	  for (int i=0; i>n &&l[i][x] &&l[i][x]!=X; i--){ l[i][x]=c;} return;}

void c2_box(c2buf *buf){
c2_vline(buf, 0); c2_vline(buf, buf->w-1);
c2_line(buf, 0); c2_line(buf, buf->h-1); return;}
void c2_fill(c2buf *buf, char c){
for (char *p =buf->c; *p; p++) for ( ; *p; p++) *p =c; return;}

void c2_rect(c2buf *buf, int y,int x,int h,int w, char c){
c2_vstroke(buf, y,x, h, c); c2_vstroke(buf, y,x+w-1, h, c);
c2_stroke(buf, y,x, w, c); c2_stroke(buf, y+h-1,x, w, c); return;}
void c2_frect(c2buf *buf, int y,int x,int h,int w, char c){
for (int i=0; i<h; i++) c2_stroke(buf, y+i,x, w, c); return;}
