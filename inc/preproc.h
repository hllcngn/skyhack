#ifndef PREPROC_H
#define PREPROC_H
#include "h.h"

//function overloads
#define space(_1,...) \
	_Generic((_1),	int:	space_yx, \
			vect:	space_vect)	(_1, __VA_ARGS__)
#define space_buf(_1,...) \
	_Generic((_1),	int:	space_buf_yx)	(_1, __VA_ARGS__)
#define vspace(_1,...) \
	_Generic((_1),	int:	vspace_yx, \
			vect:	vspace_vect)	(_1, __VA_ARGS__)

#endif
