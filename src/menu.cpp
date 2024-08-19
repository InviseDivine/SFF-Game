#include <menu.hpp>

void Menu::init() {
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "SFF Game 0.1");

    InitAudioDevice(); 

    Game::m_texture.textureLoad();
    game2.textureLoad2();
    menuTextureLoad();

    menuScreen = menu;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        cursor = GetMousePosition();
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(cursor, backCredits)) {
            game.menuSwitch = 0;
        }
        for (auto &menuAr: menuArr) {
            if (CheckCollisionPointRec(cursor, menuAr.hitbox) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                game.menuSwitch = menuAr.id;
            }
        }
        switch (game.menuSwitch) {
        // case 1:
        //     game.isGameEnd = 0;
        //     cut.cutscene();
        //     break;
        case 0:
            menuScreen = menu;
            menuArr[1].hitbox = {514, 268, 212, 60};
            menuArr[2].hitbox = {514, 355, 213, 61};
            menuArr[3].hitbox = {514, 446, 213, 61};
            backCredits = NULL_RECT;
            break;
        case 1:
            menuScreen = characterChoose;
            menuArr[1].hitbox = NULL_RECT;
            menuArr[2].hitbox = NULL_RECT;
            menuArr[3].hitbox = NULL_RECT;
                for(auto& character : characters) {
                    if(CheckCollisionPointRec(cursor, character.hitbox) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                        game.characterSwitch = character.id;
                    }
                }
            break;
        case 3:
            menuArr[1].hitbox = NULL_RECT;
            menuArr[2].hitbox = NULL_RECT;
            menuScreen = creditsTex;
            backCredits = {21,18, 83 ,37};
            break;
        }
        if (game.characterSwitch == 0) {
            game.menuSwitch = 0;
            game.characterSwitch = -1;
        }
        switch (game.menuSwitch) {
        case -1:
            break;
        case BACK:
            break;
        case NJUYSE:
            // for (auto &mapa : mapArr) {
            //     if (CheckCollisionPointRec(cursor, mapa.hitbox) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            //         game.characterSwitch = mapa.id;
            //     }
            // }
            game2.update2();
            break;
        case AMINA:
            break;
        }
        this->render();
    }

    CloseWindow();
    CloseAudioDevice();
}
void Menu::render() {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawTexture(menuScreen, 0, 0, WHITE);
    switch (game.menuSwitch) {
        case 1:
            game2.draw2();
            break;
    }
    EndDrawing();
}
void Menu::menuTextureLoad() {
    menu = LoadTexture("resources/menu.png");
    map = LoadTexture("resources/map.png");
    characterChoose = LoadTexture("resources/characterchoose.png");
    creditsTex = LoadTexture("resources/credits.png");
}