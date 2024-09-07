#pragma once

#include <stdio.h>
#include <raylib.h>
#include <NjuyseBankRobbery/hitbox.hpp>
#include <vector>
#define NULL_RECT {0, 0, 0, 0}
class PlayerBank {
private:
    enum animationsENUM { animationUp = 0, animationDown, animationLeft, animationRight
    };
    struct strRec {
        Rectangle hitbox;
    };

    int framesSpeed = 10;
    int framesCounter = 0;
    int currentFrame = 0;
    int m_animation = 0;

    float m_speedX = 0.0f;
    float m_speedZ = 0.0f;

    Rectangle m_njuyseAnim = {0, 0, 822 / 3, 1036 / 4};
    
    Vector2 m_playerPos = {0, 0};
public:
    Hitbox1 m_hitbox;

    PlayerBank();
    
    std::vector<Hitbox1> room = { 
    {223, 0, 829, 451},
    {0, 0, 81, 720}, 
    {430, 119, 306, 377},
    {1235, 0, 56, 1000},    
    {0, 721, 1280, 2},    
    {862, 451, 235, 216},
    {55, 0, 106, 580},    
    {0, 721, 1280, 2},
    {145, 0, 217, 544},
    {1059, 500, 221, 51},
    NULL_RECT// 2828, 197, 118, 459         {1198, 506, 86, 135}
    };

    float m_laserWidth = 9;
    float m_speed = 1.5f;

    Camera2D camera = { 0 };

    Rectangle m_playerRec;
    Rectangle m_table = NULL_RECT;
    Rectangle m_door = {1159, 293, 90, 323};
    Rectangle m_door2 = NULL_RECT;
    std::vector<Rectangle> laser = { 
        NULL_RECT,
        NULL_RECT,
        NULL_RECT,
        NULL_RECT,
        NULL_RECT,
        NULL_RECT,
        NULL_RECT,
        NULL_RECT,
        NULL_RECT
    };

    int m_recSwitch = 0;
    
    Texture2D m_njuyse;
    
    
    void playerDraw();
    void playerUpdate();
    void move(float x, float y);
    void restart();
};