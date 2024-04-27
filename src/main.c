#include "ogns.h"
void drawtitlescreen(SDL_Window* window, SDL_Renderer* renderer,
		SDL_Texture* t_title, SDL_Texture** t_options,
		SDL_Texture** t_select, int options_nb, int select);
#ifdef main
#undef main
#endif
int main(int ac, char** av){
//SDL init
SDL_Init(SDL_INIT_VIDEO);
TTF_Init();
SDL_Window   *window =SDL_CreateWindow("Of Glass And Steel",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		600, 400,
		SDL_WINDOW_SHOWN |SDL_WINDOW_RESIZABLE);
SDL_Renderer *renderer =SDL_CreateRenderer(window, -1,
		SDL_RENDERER_ACCELERATED);

//loading/creating title menu assets
SDL_Surface *s_title =SDL_LoadBMP("ass/title1.bmp");
SDL_Texture *t_title =SDL_CreateTextureFromSurface(renderer, s_title);
SDL_FreeSurface(s_title);
TTF_Font* sans =TTF_OpenFont("ass/TimesNewRoman.ttf",22);
SDL_Color red ={172,50,50};
int options_nb =4;
SDL_Texture** t_options =malloc(sizeof(SDL_Texture*)*options_nb);
SDL_Surface* s_option =TTF_RenderText_Solid(sans, ">   New Game ....................... (N)", red);
t_options[0] =SDL_CreateTextureFromSurface(renderer, s_option);
SDL_FreeSurface(s_option);
s_option =TTF_RenderText_Solid(sans, ">   Load Game ....................... (L)", red);
t_options[1] =SDL_CreateTextureFromSurface(renderer, s_option);
SDL_FreeSurface(s_option);
s_option =TTF_RenderText_Solid(sans, ">   Settings ............................. (S)", red);
t_options[2] =SDL_CreateTextureFromSurface(renderer, s_option);
SDL_FreeSurface(s_option);
s_option =TTF_RenderText_Solid(sans, ">   Quit .................................. (Q)", red);
t_options[3] =SDL_CreateTextureFromSurface(renderer, s_option);
SDL_FreeSurface(s_option);
SDL_Color lightblue ={95,205,228};
SDL_Texture** t_select =malloc(sizeof(SDL_Texture*)*options_nb);
s_option =TTF_RenderText_Solid(sans, ">   New Game ....................... (N)", lightblue);
t_select[0] =SDL_CreateTextureFromSurface(renderer, s_option);
SDL_FreeSurface(s_option);
s_option =TTF_RenderText_Solid(sans, ">   Load Game ....................... (L)", lightblue);
t_select[1] =SDL_CreateTextureFromSurface(renderer, s_option);
SDL_FreeSurface(s_option);
s_option =TTF_RenderText_Solid(sans, ">   Settings ............................. (S)", lightblue);
t_select[2] =SDL_CreateTextureFromSurface(renderer, s_option);
SDL_FreeSurface(s_option);
s_option =TTF_RenderText_Solid(sans, ">   Quit .................................. (Q)", lightblue);
t_select[3] =SDL_CreateTextureFromSurface(renderer, s_option);
SDL_FreeSurface(s_option);

//title screen loop
int select =0;
drawtitlescreen(window, renderer, t_title, t_options, t_select, options_nb, select);
int terminate =0;
SDL_Event e;
while(!terminate){

//event handling
while(SDL_PollEvent(&e)){
if (e.type ==SDL_QUIT)
	terminate++;
else if (e.type ==SDL_WINDOWEVENT) switch(e.window.event){
	case SDL_WINDOWEVENT_RESIZED:
		drawtitlescreen(window, renderer, t_title,
				t_options, t_select, options_nb, select);
						break;
	default:				break;}
else if (e.type ==SDL_KEYDOWN) switch(e.key.keysym.sym){
	case K_TITLE_QUIT:	terminate++;	break;
	case K_TITLE_SETT: //open settings menu loop
						break;
	case K_TITLE_NEW: //end title loop, launch game
	case K_TITLE_LOAD:			break;
	default:				break;}}
}//end of title screen loop

//SDL cleaning
SDL_DestroyTexture(t_title);
for(int i=0;i<options_nb;i++) SDL_DestroyTexture(t_options[i]); free(t_options);
//SDL end
SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);
SDL_Quit();
return 0;}


void drawtitlescreen(SDL_Window* window, SDL_Renderer* renderer,
		SDL_Texture* t_title, SDL_Texture** t_options,
		SDL_Texture** t_select, int options_nb, int select){
//background
SDL_SetRenderDrawColor(renderer, 63,63,116,0xFF);
SDL_RenderClear(renderer);
//title
int w,h; SDL_GetWindowSize(window, &w,&h);
SDL_Rect r_title =(SDL_Rect){(w-350)/2, h/4.2, 350,50};
SDL_RenderCopy(renderer, t_title, NULL, &r_title);
//options
for(int i=0;i<options_nb;i++){
	int w1,h1; SDL_QueryTexture(t_options[i],NULL,NULL,&w1,&h1);
	SDL_Rect r_option =(SDL_Rect){(w-350)/2+10, r_title.y+70+i*40, w1,h1};
	if (i==select)	SDL_RenderCopy(renderer, t_select[i], NULL, &r_option);
	else		SDL_RenderCopy(renderer, t_options[i], NULL, &r_option);}
//rendering
SDL_RenderPresent(renderer);
return;}
