#include "App.h"
#include <cstdio>
#include "Load.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

Load::~Load()
{
  if(pngSurf == NULL)
  {
      printf("Your PNG file could not be loaded!");
  }


  if(pngTex == NULL)
  printf("Image texure cannot be displayed!");



}





void Load::disp_PNG()
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



