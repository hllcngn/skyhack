#ifndef PRNG_H
#define PRNG_H
#include <stdint.h>

extern uint8_t*	seedc;
extern uint32_t	seedui[8];
extern int	seedn;

void rng_init();
void load_seed(FILE* f);
void save_states(FILE* f);

int randn();

#endif
