#pragma once
#include <raylib.h>

class Player {
private:
    Vector2 Position;
    Texture2D Player;
public:
    void update();
    void draw();
};