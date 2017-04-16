#ifndef _ENEMY_
#define _ENEMY_


#include <SDL.h>
#include "Game.h"

class Enemy {
public:
    int enemy_Health = 100;
    int x,y;
    Enemy():x(0), y(0) {}

};

