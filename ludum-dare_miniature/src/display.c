#include "INC.h"

void	display_lvl(int y,int x, LEVEL *lvl){
display_outwall(y,x);
//mvprintw(y-2+3,0, "display_outwall successful");
c2_disp(lvl->map, y,x);
//mvprintw(y-1+3,0, "c2_disp successful");
return;}

void	display_outwall(int y,int x){
int	i;  y--; x--;
pr_vstroke(y,x, '|', DGH+2);
pr_vstroke(y,x +DGW+2 -1, '|', DGH+2);
pr_stroke(y,x, '-', DGW+2);
pr_stroke(y +DGH+2 -1,x, '-', DGW+2); return;}
