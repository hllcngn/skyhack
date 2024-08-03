#ifndef PRNG_H
#define PRNG_H
#include <stdint.h>

extern uint8_t*		seedc;
extern int		stateN;
extern uint32_t*	state;
extern int		staten;

//prng.c
int	rn(int max); //0-max inclusive
int	rrange(int min,int max); //inclusive

int	randn();

void	load_rng(FILE* f);
void	save_rng(FILE* f);

void	debug_seed(WINDOW* w);

#endif
