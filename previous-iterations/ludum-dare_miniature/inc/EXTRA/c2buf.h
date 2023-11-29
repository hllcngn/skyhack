#pragma once

typedef struct{
	int	h,w, htot,wtot, sizetot;
	char	*b,*c;
	char	**k,**l;
} c2buf;

//c2buf.c
c2buf	*alloc_c2buf(int,int);
void	free_c2buf(c2buf*);

void	c2_print(c2buf*);
void	c2_disp(c2buf*, int,int);

//c2brush.c
void c2_line(c2buf *buf, int y);
void c2_vline(c2buf *buf, int x);
void c2_stroke(c2buf*, int,int, int, char);
void c2_vstroke(c2buf*, int,int, int, char);
void c2_stroketil(c2buf *buf, int y,int x, int n, char c, char X);
void c2_vstroketil(c2buf *buf, int y,int x, int n, char c, char X);
void c2_box(c2buf*);
void c2_fill(c2buf *buf, char c);
void c2_rect(c2buf *buf, int y,int x,int h,int w, char c);
void c2_frect(c2buf *buf, int y,int x,int h,int w, char c);
