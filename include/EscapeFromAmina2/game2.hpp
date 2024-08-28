#pragma once
#include <raylib.h>
#include <EscapeFromAmina2/player.hpp>
#include <vector>
class Game2 {
private:
    Player player;
    
    int m_nextSwitch = 1;

    Vector2 m_cursor;

    Texture2D m_screen;
    Texture2D m_cutscene;
    Texture2D m_cutscene2;
    Texture2D m_cutscene3;
    Texture2D m_cutscene4;
    Texture2D m_bg;
    Texture2D m_bg2;
    Texture2D m_bg3;
    Texture2D m_playerNjuyse;
    Texture2D m_bgSecondFloor;
    // Texture2D m_zamokTex;
    // Texture2D m_otmichkaTex;

    Rectangle m_nextButton = {1119, 584, 161, 135};
public:
    void textureLoad2();
    void cutscene2();
    void update2();
    void draw2();
    void zamok();
};