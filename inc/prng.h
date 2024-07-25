#ifndef PRNG_H
#define PRNG_H
#include <stdint.h>

extern uint8_t*	seedc;
extern uint32_t	seedui[8];
extern int	seedn;

//prng.c
int	randn();

void	rng_init();
void	load_seed(FILE* f);
void	make_states();
void	save_states(FILE* f);

void	debug_seed(WINDOW* w);

//rngbrush.c
int	rn(int max); //0-max inclusive
int	rrange(int min,int max); //inclusive

#endif
