#pragma once
#include <raylib.h>
#include <vector>
#include <stdio.h> 
#include <raymath.h>
#include <cmath>
#include <EscapeFromAmina2/hitbox.hpp>
#include <vector>
#define NULL_RECT {0, 0, 0, 0}
class Player {
private:
    enum doorsENUM { doorUP = 0, doorNEXT, doorBACK, secondFloor
    };
    struct strZamok {
        Rectangle hitbox;
        bool isPressed;
    };
    Hitbox m_hitbox;
    
    int m_att = 0;

    // float startY = 450;
    // float startLockX = 660 + 212;
    // float m_stickX = 212;
    // float m_stickY = 450 + 212;
    // float m_stickWidth = 30;
    // float m_stickHeight = 112;

    // float m_otmichkaSpeed = 1.0f;
    float m_speed = 1.5f;
    float m_speedX = 0.0f;
    float m_speedZ = 0.0f;

    bool isOtmichka = false;
    // bool tryingUnlock = false;
    
    // double lastUnlockTime = 0.0f;

    // std::vector<int> caughtSticks;
    // std::vector<float> m_sticks = {
    //     m_stickY,
    //     m_stickY,
    //     m_stickY,
    //     m_stickY,
    //     m_stickY
    // };
public:
    Rectangle m_doorUp = {187, 207, 177, 304};
    Rectangle m_doorNextRoom = {25, 259, 70, 330};
    Rectangle m_doorBack = NULL_RECT; // 1196, 246, 58, 383
    Rectangle m_playerRec;
    Rectangle m_otmichkaRec = NULL_RECT;
    Rectangle m_stairRec = NULL_RECT;
    Rectangle m_stairBackRec = NULL_RECT;

    Vector2 m_playerVec;

    int m_cameraOff;
    int m_cameraOff2;
    Camera2D camera = { 0 };

    int m_switchDoors = -1;

    Player();

    Vector2 m_otmichkaPos = {0, 450};
    std::vector<Hitbox> room = { 
        {0, 65, 1280, 435},
        {0, 0, 81, 629},
        {10, 646, 38, 92},
        {1235, 0, 47, 1000},    
        {0, 721, 720, 1}    
    };

    void playerUpdate();
    void playerDraw();
    void move(float x, float y);
    void moveRelative(float xa, float za, float speed);
    void zamok();
};