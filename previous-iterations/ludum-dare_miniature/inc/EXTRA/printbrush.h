#ifndef PRINTBRUSH_H
#define PRINTBRUSH_H

#include "INC.h"

//function overloads
#define pr_stroke(_1,...) \
	_Generic((_1),	int:	pr_stroke_yx, \
			vect:	pr_stroke_vect)	(_1, __VA_ARGS__)
#define pr_vstroke(_1,...) \
	_Generic((_1),	int:	pr_vstroke_yx, \
			vect:	pr_vstroke_vect)	(_1, __VA_ARGS__)

void pr_stroke_yx(int y,int x, char c, int n);//todo:swap c and n args
void pr_stroke_vect(vect coord, char c, int n);
void pr_stroke1in2(int y,int x, char c1,char c2, int n);
void pr_vstroke_yx(int y,int x, char c, int n);
void pr_vstroke_vect(vect coord, char c, int n);
void pr_fill_term(char c);
void pr_fill(int y,int x, char c, int h,int w);
void pr_box(int y,int x, char c, int h,int w);

#endif
