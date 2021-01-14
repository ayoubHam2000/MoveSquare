#include <mainHeader.h>



void drawRect(SDL_Renderer *renderer, SDL_Rect rect){
    SDL_Rect newRect;

    newRect.x = rect.x * UNIT_X;
    newRect.y = rect.y * UNIT_Y;
    newRect.w = rect.w * UNIT_X;
    newRect.h = rect.h * UNIT_Y;

    SDL_RenderFillRect(renderer, &newRect);
    SDL_RenderPresent(renderer);
}



void clear(SDL_Renderer *renderer){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderPresent(renderer);
}
