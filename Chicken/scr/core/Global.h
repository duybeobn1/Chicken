#ifndef GLOBAL_H_
#define GLOBAL_H_

#include <vector>
#include <string.h>
#include <math.h>
#include <cassert>
#include <iostream>
using namespace std;
const int BACKGROUND_WIDTH = 1200;
const int BACKGROUND_HEIGHT = 3840;
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 760;
const float SCREEN_SPEED = 0.3;

const int COLOR_KEY_R = 170;
const int COLOR_KEY_G = 170;
const int COLOR_KEY_B = 170;
const int RENDER_DRAW_COLOR = 255;

const int NUMBER_OF_CHICKEN = 36;
const int ONE_TURN_GIFT = 14;
const int NUMBER_OF_EXP = 3; 
const int BOSS_HEART = 3;
const int DISTANCE_BETWEEN_CHICKENS = 100;
const int NUMBER_OF_CHICKEN_PER_ROW = 12;
const float BULLET_DAMAGE_LEVEL_UP = 0.5;
const int BLASTER = 0 ; 
const int NEUTRON = 1; 
const int BORON = 2 ; 
const int LEVEL_UP = 3; 


struct StatusChicken
{
    int turn_left;
    int turn_right;
    int turn_up;
    int turn_down;
};

#endif