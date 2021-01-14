#ifndef MOVESQUARE_MYSTRUCT_H
#define MOVESQUARE_MYSTRUCT_H

struct My_Vect2D{
    int x;
    int y;
};
typedef struct My_Vect2D My_Vect2D;

struct My_color{
    unsigned short r;
    unsigned short g;
    unsigned short b;
    unsigned short a;
};
typedef struct My_color My_color;

struct My_Rect{
    SDL_Rect rect;
    My_color color;
};
typedef struct My_Rect My_Rect;



#endif //MOVESQUARE_MYSTRUCT_H
