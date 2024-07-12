#ifndef PROTOTYPES_H
#define PROTOTYPES_H
#include "h.h"

//game.c
int	game(GAME* gm);

//player_actions.c
vect	player_move(char k, vect pos, char *clsn);

//draw.c
void	draw_level(char *clsn, buf1 b);
void	draw_empty_level();
void	draw_entire_floor();
void	draw_enclosing_walls();
void	draw_floor_at(vect pos);
void	draw_path(vect* pts, int n);
void	draw_path2(vect* pts, int n);
//printbrush.c
void	space_yx(int y,int x, char c, int n);
void	space_buf_yx(int y,int x, char c, int n, char **cbuf);
void	space_vect(vect coord, char c, int n);
void	space1in2(int y,int x, char c1,char c2, int n);
void	vspace_yx(int y,int x, char c, int n);
void	vspace_vect(vect coord, char c, int n);
void	box_space(int y,int x, char c, int h,int w);
void	fill_term(char c);
void	fill_space(int y,int x, char c, int h,int w);
void stroke(vect p1, vect p2, char c);


//main.c
int	title();

//main2.c
int	main2(GAME* gm);

//generate.c
void	make_level(char *clsn, buf1 b);
void	make_static_walls(char* clsn);
void	make_random_walls();
//rngbrush.c
int	rn(int max); //0-max inclusive
int	rrange(int min,int max); //inclusive



//buf.c
void save_buf(char* file, buf1 b);

#endif
