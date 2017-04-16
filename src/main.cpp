// main.cpp
// app entry point.
//
// Author: yat0 - https://github.com/yat0

#include "App.h"
#include <cstdio>



int main(int argc, char *args[])
{
    App app1;

    if(!app1.init())
    {
        printf("Error initializing... bye!\n");
        return 0;
    }
    app1.start();
    app1.run();

    SDL_Surface * image = IMG_Load("sprite.png");




    return 0;
}
