#pragma once

#include <raylib.h>
#include <algorithm>

class Hitbox {
public:
    float x;
    float y;
    float width;
    float height;

    Hitbox(float x, float y, float width, float height);
    
    float clipXCollide(Hitbox& other, float xa);
    float clipZCollide(Hitbox& other, float za);
    
    void move(float x, float y);
};