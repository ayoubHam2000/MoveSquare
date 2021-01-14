#include <mainHeader.h>
#define TimeFrame 16

SDL_Window *window;
SDL_Renderer *renderer;

SDL_Rect rect = {1, 1, 1, 1};

#pragma region controller

void onLeft(){
    if(rect.x - 1 >= 0){
        rect.x--;
    }else{
        rect.x = 800 / UNIT_X - 1;
    }
    printf("Left\n");
    clear(renderer);
    drawRect(renderer, rect);
}

void onRight(){
    if(rect.x + 1 < 800 / UNIT_X){
        rect.x++;
    }else{
        rect.x = 0;
    }
    printf("Right\n");
    clear(renderer);
    drawRect(renderer, rect);
}

void onUp(){
    if(rect.y - 1 >= 0 / UNIT_Y){
        rect.y--;
    }else{
        rect.y = 600 / UNIT_Y - 1;
    }
    printf("UP\n");
    clear(renderer);
    drawRect(renderer, rect);
}

void onDown(){
    if(rect.y + 1 < 600 / UNIT_Y){
        rect.y++;
    }else{
        rect.y = 0;
    }
    printf("Down\n");
    clear(renderer);
    drawRect(renderer, rect);

}

void controller(SDL_KeyCode keyCode){
    switch (keyCode) {
        case SDLK_DOWN:
            onDown();
            break;
        case SDLK_UP:
            onUp();
            break;
        case SDLK_LEFT:
            onLeft();
            break;
        case SDLK_RIGHT:
            onRight();
            break;
        default:
            break;
    }
}

void frameController(unsigned int limit){
    unsigned int time = SDL_GetTicks();

    if(limit < time){
        return;
    }else{
        SDL_Delay(limit - time);
    }
}

#pragma endregion

void sdlEvent(){
    SDL_bool running = SDL_TRUE;
    SDL_Event event;
    unsigned int timer = SDL_GetTicks();

    while(running){
        timer += TimeFrame;

        while (SDL_PollEvent(&event)){
            switch (event.type) {
                case SDL_QUIT:
                    running = SDL_FALSE;
                    break;

                case SDL_KEYDOWN:
                    controller(event.key.keysym.sym);
                    break;
                default:
                    break;
            }
        }
        frameController(timer);
    }
}

void textRenderer(){
    SDL_Texture *texture = NULL;
    SDL_Surface* textSurface = NULL;
    TTF_Font* font = NULL;
    SDL_Rect textLocation = { 100, 100, 100, 100 };
    SDL_Color foregroundColor = { 255, 0, 0, 255};

    TTF_Init();
    font = TTF_OpenFont("../src/fonts/OpenSans-SemiboldItalic.ttf", 60);


    textSurface = TTF_RenderText_Solid(font, "This is my text.", foregroundColor);
    texture = SDL_CreateTextureFromSurface(renderer, textSurface);

    SDL_QueryTexture(texture, NULL, NULL, &textLocation.w, &textLocation.h);
    SDL_RenderCopy(renderer, texture, NULL, &textLocation);
    SDL_RenderPresent(renderer);

    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
}

void onStart(){
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderPresent(renderer);
    drawRect(renderer, rect);


    textRenderer();
    //SDL_Delay(5000);
    sdlEvent();
}

int main(int argc, char **argv) {
    initSDL(&window, &renderer);
    onStart();


    TTF_Quit();
    quit(window, renderer);
    return 0;
}
