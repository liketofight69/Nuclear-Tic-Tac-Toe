#ifndef _SPRITE_
#define _SPRITE_


#include <SDL.h>
#include "Game.h"

class Sprite {
public:
    int player_Health = 100;
    int x,y;
    Sprite():x(0), y(0) {}

};
