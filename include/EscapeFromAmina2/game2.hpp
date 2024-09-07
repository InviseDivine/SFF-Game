#pragma once
#include <raylib.h>
#include <EscapeFromAmina2/player.hpp>
#include <vector>
#include "EscapeFromAmina/textureload.hpp"
class Game2 {
private:
    Player player;
    texture textur;

    bool isEscape = false;

    int m_framesCounter = 0;
    int m_frameSpeed = 10;
    int m_nextSwitch = 1;
    int m_currentFrame = 0;
    
    float m_aminaSpeed = 4;
    float m_posScreen = 0;

    Vector2 m_cursor;
    Vector2 m_aminaPos = {0, 0};


    Texture2D m_nextbutt;
    Texture2D m_screen;
    Texture2D m_cutscene;
    Texture2D m_cutscene2;
    Texture2D m_cutscene3;
    Texture2D m_cutscene4;
    Texture2D m_bg;
    Texture2D m_bg2;
    Texture2D m_bg3;
    Texture2D m_bgSecondFloor;
    Texture2D m_bgAmina;
    Texture2D m_pyatno;
    Texture2D m_forest;
    Texture2D m_otmichkaMini;
    Texture2D m_empty;
    Texture2D m_amina;
    // Texture2D m_zamokTex;
    // Texture2D m_otmichkaTex;
    Rectangle m_aminaR = {0, 0, 130 / 2, 165};
    Rectangle m_aminaCheck = {m_aminaPos.x, m_aminaPos.y, 65, 165};
    Rectangle m_nextButton = {1119, 584, 161, 135};
public:
    void escape();
    void textureLoad2();
    void cutscene2();
    void update2();
    void draw2();
    void zamok();
};