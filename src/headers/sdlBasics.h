#ifndef MOVESQUARE_SDLBASICS_H
#define MOVESQUARE_SDLBASICS_H


SDL_Renderer *initRenderer(SDL_Window *window);
void initSDL(SDL_Window **window, SDL_Renderer **renderer);
SDL_Window *initWindow(int w, int h);
void sdlError(const char *error);
void quit(SDL_Window *window, SDL_Renderer *renderer);


#endif //MOVESQUARE_SDLBASICS_H
