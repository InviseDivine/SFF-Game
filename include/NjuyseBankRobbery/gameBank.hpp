#pragma once
#include <raylib.h>

class Game2 {
private:
public:
};
class Player {
private:
    int m_speed;
    Vector2 m_position;
    Texture2D m_texture;
public:
    void update();
    void draw();
};