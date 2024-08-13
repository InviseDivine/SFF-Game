#include "EscapeFromAmina/cutscene.hpp"
#include "raylib.h"
Game next;
void Cutscene::cutscene() {
    Vector2 mouse = GetMousePosition();
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mouse, hitboxnext)) {
        game.plusplus++;
    }
    switch(game.plusplus) {
        case 0:
            Game::m_texture.m_onScreen = Game::m_texture.m_cut1;
            hitboxnext = {1111,582,200,100};
            break;
        case 1:
            Game::m_texture.m_onScreen = Game::m_texture.m_cut2;
            break;
        case 2:
            Game::m_texture.m_onScreen = Game::m_texture.m_cut3;
            break;
        case 3:
            Game::m_texture.m_onScreen = Game::m_texture.m_cut4;
            break;
        case 4:
            Game::m_texture.m_onScreen = Game::m_texture.m_cut5;
            break;
        case 5:
            Game::m_texture.m_onScreen = Game::m_texture.m_cut6;
            break;
        case 6:
            Game::m_texture.m_onScreen = Game::m_texture.m_cut7;
            break;
        case 7:
            Game::m_texture.m_onScreen = Game::m_texture.m_cut8;
            break;
        case 8:
            Game::m_texture.m_onScreen = Game::m_texture.m_cut9;
            break;
        case 9:
            Game::m_texture.m_onScreen = Game::m_texture.m_room;
            Game::m_texture.m_nextbutton = Game::m_texture.m_backempty;
            hitboxnext = {-1,-1,-1,-1};
            next.update();
            break;
    }
}