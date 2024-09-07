#pragma once

#include <raylib.h>
#include <NjuyseBankRobbery/player.hpp>
#include <stdio.h>
#define NULL_RECT {0, 0, 0, 0}
class gameBank {
private:
    PlayerBank player;

    Vector2 m_copPos = {0, 0};

    int m_framesCounter = 0;
    int m_frameSpeed = 10;
    int m_nextSwitch = 1;
    int m_currentFrame = 0;
    
    float m_copSpeed = 4;

    Vector2 m_cursor;

    bool isRun = false;
    
    Rectangle m_copRec = {0, 0, 80 / 2, 132};
    Rectangle m_chooseRec = NULL_RECT;
    Rectangle m_copRecCheck = {m_copPos.x, m_copPos.y, 80 / 2, 1000};
    
    Texture2D m_cop;
    Texture2D m_laserRoom1;
    Texture2D m_laserRoom2;
    Texture2D m_screen;
    Texture2D m_endRoom;
    Texture2D m_choose;
    Texture2D m_runBG;
public:
    void run();
    void textureLoad();
    void update();
    void draw();
};