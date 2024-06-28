#ifndef PROTOTYPES_H
#define PROTOTYPES_H
#include "h.h"

//game.c
void	game();

//player_actions.c
vect	player_move(char k, vect pos, char **clsn);

//draw.c
void	draw_empty_level();
void	make_level(char **clsn);
void	draw_enclosing_walls();
void	draw_entire_floor();
void	draw_floor_at(vect pos);
//printbrush.c
void	space_yx(int y,int x, char c, int n);
void	space_buf_yx(int y,int x, char c, int n, char **cbuf);
void	space_vect(vect coord, char c, int n);
void	space1in2(int y,int x, char c1,char c2, int n);
void	vspace_yx(int y,int x, char c, int n);
void	vspace_vect(vect coord, char c, int n);
void	fill_term(char c);
void	fill_space(int y,int x, char c, int h,int w);
void	box_space(int y,int x, char c, int h,int w);

//generate.c
void	generate_static_walls();
void	generate_random_walls();
//rngbrush.c
int	rn(int max); //0-max inclusive
int	rrange(int min,int max); //inclusive

#endif
