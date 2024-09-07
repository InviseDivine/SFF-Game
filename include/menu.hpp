#pragma once
#include <EscapeFromAmina2/game2.hpp>
#include <EscapeFromAmina/game.hpp>
#include "EscapeFromAmina/textureload.hpp"
#include "EscapeFromAmina/cutscene.hpp"
#include <NjuyseBankRobbery/bankGame.hpp>
#include <raylib.h>

class Menu {
private:
    #define NULL_RECT {0, 0, 0, 0}
    typedef enum charactersENUM { BACK = 0, NJUYSE, AMINA, DIVAN
    }; // ( ͡° ͜ʖ ͡°) WTF NEXT UPDATE LEAK???
    typedef enum mapENUM { BACKMAP = 0, AMINAHOME, PODVAL, BANK
    };
    struct HitboxEvent {
        Rectangle hitbox;
        int id;
    };
        
    gameBank bank;
    Game game;
    Cutscene cut;
    Game2 game2;
    
    int Get1;

    Texture2D menu;
    Texture2D menuScreen;
    Texture2D characterChoose;
    Texture2D map;
    Texture2D creditsTex;

    Rectangle backCredits = NULL_RECT;

    Vector2 cursor;
    // std::vector<HitboxEvent> characters = {
    //     {{111, 219, 52, 24}, 0}, 
    //     {{165, 257, 133, 119}, 1}, 
    //     {{522, 237, 168, 97}, 2}, 
    //     {{852, 237, 215, 199}, 3}
    // };
    std::vector<HitboxEvent> mapArr = {
        {NULL_RECT, 0}, 
        {NULL_RECT, 1}, 
        {NULL_RECT, 2}, 
        {NULL_RECT, 3}
    };
    std::vector<HitboxEvent> menuArr = {
        {NULL_RECT, 0}, 
        {{514, 268, 212, 60}, 1}, 
        {{514, 355, 213, 61}, 2}, 
        {{514, 446, 213, 61}, 3}
    };
public:
    void menuTextureLoad();
    void update();
    void init();
    void render();
};