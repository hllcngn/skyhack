#include "ogns.h"
void drawtitlescreen(SDL_Window *window, SDL_Renderer *renderer,
		SDL_Texture *t_title, SDL_Texture *t_option1);
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

SDL_Surface *s_title =SDL_LoadBMP("ass/title1.bmp");
SDL_Texture *t_title =SDL_CreateTextureFromSurface(renderer, s_title);
SDL_FreeSurface(s_title);

TTF_Font* sans =TTF_OpenFont("ass/Freedom-10eM.ttf",24);
SDL_Color red ={172,50,50};
SDL_Surface *s_option1 =TTF_RenderText_Solid(sans, "> New Game (n)", red);
SDL_Texture *t_option1 =SDL_CreateTextureFromSurface(renderer, s_option1);
SDL_FreeSurface(s_option1);

//title screen loop
drawtitlescreen(window, renderer, t_title, t_option1);
int terminate =0;
SDL_Event e;
while(!terminate){

//event handling
while(SDL_PollEvent(&e)){
if (e.type ==SDL_QUIT)
	terminate++;
else if (e.type ==SDL_WINDOWEVENT) switch(e.window.event){
	case SDL_WINDOWEVENT_RESIZED:
		drawtitlescreen(window, renderer, t_title, t_option1);
					break;
	default:			break;}
else if (e.type ==SDL_KEYDOWN) switch(e.key.keysym.sym){
	case K_QUIT:	terminate++;	break;
	default:			break;}}
}//end of title screen loop

//SDL cleaning
SDL_DestroyTexture(t_title);
SDL_DestroyTexture(t_option1);
//SDL end
SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);
SDL_Quit();
return 0;}


void drawtitlescreen(SDL_Window *window, SDL_Renderer *renderer,
		SDL_Texture *t_title, SDL_Texture *t_option1){
//background
SDL_SetRenderDrawColor(renderer, 63,63,116,0xFF);
SDL_RenderClear(renderer);
//title
int w,h; SDL_GetWindowSize(window, &w,&h);
SDL_Rect r_title =(SDL_Rect){(w-350)/2, h/4, 350,50};
SDL_RenderCopy(renderer, t_title, NULL, &r_title);
//options
int w1,h1; SDL_QueryTexture(t_option1,NULL,NULL,&w1,&h1);
SDL_Rect r_option1 =(SDL_Rect){(w-w1)/2, h/2, w1,h1};
SDL_RenderCopy(renderer, t_option1, NULL, &r_option1);
//rendering
SDL_RenderPresent(renderer);
return;}
