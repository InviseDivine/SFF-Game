#pragma once

#include <raylib.h>
#include <algorithm>

class Hitbox1 {
public:
    float x;
    float y;
    float width;
    float height;

    Hitbox1(float x, float y, float width, float height);
    
    float clipXCollide(Hitbox1& other, float xa);
    float clipZCollide(Hitbox1& other, float za);
    
    void move(float x, float y);
};