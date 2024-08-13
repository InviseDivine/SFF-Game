#pragma once
#include "raylib.h"
#include "game.hpp"
#include "EscapeFromAmina/textureload.hpp"
class Cutscene {
private:
    Game game;
    Rectangle hitboxnext = {1111,582,200,100};
public: 
    void cutscene();
};