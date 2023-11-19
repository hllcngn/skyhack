#ifndef STRUCT_H
#define STRUCT_H

typedef struct{
	int	y;
	int	x;} vect;

typedef struct{
	int	lines;
	int	cols;
	char	**b;} c2buf;

typedef struct{
	int	lines;
	int	cols;
	int	depth;
	char	***b;} c3buf;

#endif
