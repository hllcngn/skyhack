#ifndef PROTOTYPES_H
#define PROTOTYPES_H
#include "h.h"

//game.c
int	game(GAME* gm);

//player_actions.c
void	player_move(char k, vect* pos, char *clsn);

//draw.c
void draw_buf(buf1 b);
void	draw_level(char* clsn, int w, buf1 b);
void	draw_empty_level(char* clsn, int w);
void	draw_entire_floor();
void	draw_enclosing_walls(char* clsn, int w);
void	draw_floor_at(vect pos);
//printbrush.c
void	space_yx(int y,int x, char c, int n);
void	space_vect(vect coord, char c, int n);
void	space_buf_yx(int y,int x, char c, int n, char **cbuf);
void spaceb1(buf1 b, int y, int x, char c, int n);
void spaceb0(char* b, int w, int y, int x, char c, int n);
void	space1in2(int y,int x, char c1,char c2, int n);
void	vspace_yx(int y,int x, char c, int n);
void	vspace_vect(vect coord, char c, int n);
void vspaceb1(buf1 b, int y, int x, char c, int n);
void vspaceb0(char* b, int w, int y, int x, char c, int n);
void	box_space(int y,int x, char c, int h,int w);
void boxb1(buf1 b, int y, int x, char c, int h, int w);
void	path(vect* pts, int n);
void	fill_term(char c);
void	fill_space(int y,int x, char c, int h,int w);
void stroke(vect p1, vect p2, char c);
void bstroke(buf1 b, vect p1, vect p2, char c);


//main.c
int	title();
void	seed_selection();

//main2.c
int	main2(GAME* gm, int new_player);

//generate.c
void	make_level(char *clsn, buf1 b);
void	make_static_walls(char* clsn, buf1 b);
void	make_random_walls(buf1 b);
//rngbrush.c
int	rn(int max); //0-max inclusive
int	rrange(int min,int max); //inclusive



//buf.c
char* itos(unsigned int i);
unsigned int stoi(char* buf);
void save_buf(FILE* f, buf1 b);
void load_buf(FILE* f, buf1* b);
void debug_buf(WINDOW* w, buf1 b);

#endif
