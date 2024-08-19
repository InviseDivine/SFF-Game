#pragma once
#include <raylib.h>
#include <vector>
#include <stdio.h> 
#include <raymath.h>
#include <cmath>
#include <EscapeFromAmina2/hitbox.hpp>

class Player {
private:
    Hitbox m_hitbox;

    Texture2D m_player;

    float m_speedX = 0.0f;
    float m_speedZ = 0.0f;
    // Vector2 m_moveDelta;
public:
    Player();
    std::vector<Hitbox> room = { 
        {0,0,1108,441},
        {800,500,10,10}
    };
    void playerUpdate();
    void playerDraw();
    void move(float x, float y);
    void moveRelative(float xa, float za, float speed);
};