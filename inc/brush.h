#ifndef PRINTBRUSH_H
#define PRINTBRUSH_H
void fill_term(char c);
void fill_space(int y,int x, char c, int h,int w);

void space_yx(int y,int x, char c, int n);
void space_vect(vect coord, char c, int n);
void spaceb0(char* b, int w, int y, int x, char c, int n);
void space_buf_yx(int y,int x, char c, int n, char **cbuf);
void spaceb1(buf1 b, int y, int x, char c, int n);

void space1in2(int y,int x, char c1,char c2, int n);

void vspace_yx(int y,int x, char c, int n);
void vspace_vect(vect coord, char c, int n);
void vspaceb0(char* b, int w, int y, int x, char c, int n);
void vspaceb1(buf1 b, int y, int x, char c, int n);

void stroke(vect p1, vect p2, char c);
void bstroke(buf1 b, vect p1, vect p2, char c);

void box_space(int y,int x, char c, int h,int w);
void boxb1(buf1 b, int y, int x, char c, int h, int w);

void path(vect* pts, int n);
#endif
