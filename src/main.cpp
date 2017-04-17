// main.cpp
// app entry point.
//
// Author: yat0 - https://github.com/yat0

#include "App.h"
#include <cstdio>
#include "main.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

 void main1::disp_PNG()
   {


    SDL_Surface * pngSurf = IMG_Load("sprite.PNG");
    SDL_Texture * pngTex = SDL_CreateTextureFromSurface(App::getRenderer(), pngSurf);
    SDL_FreeSurface(pngSurf);

    SDL_Texture * texTarget = SDL_CreateTexture(App::getRenderer(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET,SCREEN_WIDTH,SCREEN_HEIGHT);


    SDL_SetRenderTarget(App::getRenderer(),texTarget);
    SDL_RenderClear(App::getRenderer());
    SDL_RenderCopy(App::getRenderer(), pngTex, NULL, NULL);

    SDL_SetRenderTarget(App::getRenderer(), NULL);

    SDL_RenderClear(App::getRenderer());
    SDL_RenderCopyEx(App::getRenderer(),texTarget, NULL, NULL, 0, NULL, SDL_FLIP_VERTICAL);
    SDL_RenderPresent(App::getRenderer());
   }















int main(int argc, char *args[])
{
    //IMG_INIT(IMG_INIT_PNG);

    App app1;

    if(!app1.init())
    {
        printf("Error initializing... bye!\n");
        return 0;
    }
    //app1.start();
    //app1.run();


    //SDL_Surface * image = IMG_Load("sprite.png");
    //SDL_Texture * texture = SDL_CreateTextureFromSurface(getRenderer,image);



    app1.run();




    return 0;
}

