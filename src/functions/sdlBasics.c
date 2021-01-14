#include <mainHeader.h>

void sdlError(const char *error){
    printf("SDL error %s -> %s\n", error, SDL_GetError());
    SDL_Quit();
    exit(1);
}

#pragma region window renderer init
SDL_Window *initWindow(int w, int h){
    SDL_Window *window;

    window = SDL_CreateWindow("Move Square",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              w,
                              h,
                              SDL_WINDOW_SHOWN
    );

    if(window == NULL){
        sdlError("Can't initialized window");
    }

    return window;
}

SDL_Renderer *initRenderer(SDL_Window *window){
    SDL_Renderer *renderer;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if(renderer == NULL){
        sdlError("failed to initialized renderer");
    }

    if(SDL_RenderClear(renderer) != 0){sdlError("Render Clear Failed");}
    return renderer;
}

void initSDL(SDL_Window **window, SDL_Renderer **renderer){

    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        sdlError("SDL can't initialized");
    }

    *window = initWindow(800, 600);
    *renderer = initRenderer(*window);
    SDL_RenderPresent(*renderer);
}

#pragma endregion

void quit(SDL_Window *window, SDL_Renderer *renderer){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}




