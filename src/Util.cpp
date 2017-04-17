// Util.cpp
// Util class member-functions definition.
//
// Author: yat0 - https://github.com/yat0

#include "Util.h"
#include "App.h"
#include <cmath>
#include <stdio.h>

// render cross on board field (row, col)
void Util::drawCross(int row, int col)
{
    int fieldW = App::SCREEN_WIDTH/3;
    int fieldH = App::SCREEN_HEIGHT/3;

    IMG_Init(IMG_INIT_PNG);
    SDL_Surface * image = IMG_Load("sprite.PNG");

    if(!image) {
        printf("IMG_LOAD: %s\n", IMG_GetError());
    }


    SDL_Texture * texture = SDL_CreateTextureFromSurface(App::getRenderer(),image);



    // top left to bottom right
    SDL_SetRenderDrawColor(App::getRenderer(),//SDL_Render_DrawLine
        col*fieldW, row*fieldH,
        col*fieldW+fieldW, row*fieldH+fieldH);

    // top right to bottom left


    SDL_RenderDrawLine(App::getRenderer(),
        col*fieldW, row*fieldH+fieldH,
        col*fieldW+fieldW, row*fieldH);

    SDL_RenderDrawLine(App::getRenderer(),
        col*fieldW, row*fieldH,
        col*fieldW+fieldW, row*fieldH+fieldH);






    SDL_FreeSurface(image);



}



// render circle on board field (boardX, boardY)
void Util::drawCircle(int row, int col)
{
    int fieldW = App::SCREEN_WIDTH/3;
    int fieldH = App::SCREEN_HEIGHT/3;

    // calculate circle center
    int centerX = col*fieldW+(fieldW/2);
    int centerY = row*fieldH+(fieldH/2);

    int r = fieldW/2;

    double step = 2*M_PI/30;
    int endX = centerX + r;
    int endY = centerY;

    // draw circle.. Multiple straight lines between consecutive
    // points of the desired circle
    for(double angle=0; angle<2*M_PI; angle+=step)
    {
        int startX = endX;
        int startY = endY;
        endX = r * cos(angle) + centerX;
        endY = r * sin(angle) + centerY;
        SDL_RenderDrawLine(App::getRenderer(), startX, startY, endX, endY);

    }
}
