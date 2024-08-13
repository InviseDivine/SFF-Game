#pragma once
#include <EscapeFromAmina/game.hpp>
#include "EscapeFromAmina/textureload.hpp"
#include "EscapeFromAmina/cutscene.hpp"
#include <raylib.h>

class Menu {
private:
    #define NULL_RECT {0, 0, 0, 0}
    typedef enum charactersENUM { BACK = 0, NJUYSE, LOCKED 
    };
    struct HitboxEvent {
        Rectangle hitbox;
        int id;
    };
    Game game;
    Bank
    Cutscene cut;
    int Get1;
    Texture2D menu;
    Texture2D menuScreen;
    Texture2D characterChoose;
    Rectangle play = {8, 187, 176, 72};
    Rectangle codes = {41, 258, 138, 48};
    Rectangle credits = {75, 333, 135, 35};
    Vector2 cursor;
    std::vector<HitboxEvent> characters = {
        {{372, 219, 52, 24}, 0}, 
        {{421, 258, 84, 89}, 1}, 
        {{603, 259, 84, 89}, 2}, 
        {{785, 259, 84, 89}, 3}
    };
public:
    void update();
    void init();
    void render();
};