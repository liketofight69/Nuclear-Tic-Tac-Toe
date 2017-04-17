#include "Game.h"

#ifndef _LOAD_
#define _LOAD_

#include <SDL.h>
#include <SDL_image.h>
#include "Game.h"





class Load
{
 public:

   ~Load();

    void disp_PNG();

 private:
    SDL_Surface * pngSurf;
    SDL_Texture * pngTex;


};
#endif
