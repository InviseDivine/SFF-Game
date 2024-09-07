#include <menu.hpp>

void Menu::init() {
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "SFF Game 1.0");

    InitAudioDevice(); 

    Game::m_texture.textureLoad();
    game2.textureLoad2();
    menuTextureLoad();
    bank.textureLoad();

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
            for(int i = 0; i > mapArr.size(); i++) {
                mapArr[i].hitbox = NULL_RECT;
            }
            mapArr[2].hitbox = NULL_RECT;
            backCredits = NULL_RECT;
            break;
        case 1:
            menuScreen = map;
            menuArr[1].hitbox = NULL_RECT;
            menuArr[2].hitbox = NULL_RECT;
            menuArr[3].hitbox = NULL_RECT;
            for (auto &mapa : mapArr) {
                if (CheckCollisionPointRec(cursor, mapa.hitbox) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    game.characterSwitch = mapa.id;
                }
            }
            mapArr[0].hitbox = {111, 219, 52, 24};
            mapArr[1].hitbox = {165, 257, 133, 119};
            mapArr[2].hitbox = {522, 237, 168, 97};
            mapArr[3].hitbox = {852, 237, 215, 199};
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
        // switch (game.menuSwitch) {
        // case -1:
        //     break;
        // case BACK:
        //     break;
        // case NJUYSE:
        //     // for (auto &mapa : mapArr) {
        //     //     if (CheckCollisionPointRec(cursor, mapa.hitbox) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        //     //         game.characterSwitch = mapa.id;
        //     //     }
        //     // }
        //     break;
        // case AMINA:
        //     break;
        // }
        switch (game.characterSwitch) {
            case 1:
                game.menuSwitch = 0;
                game.isGameEnd = 0;
                cut.cutscene();
                for(int i = 0; i > mapArr.size(); i++) {
                    mapArr[i].hitbox = NULL_RECT;
                }
        
                break;
            case 2:
                game.menuSwitch = 0;
                game2.update2();
                for(int i = 0; i > mapArr.size(); i++) {
                    mapArr[i].hitbox = NULL_RECT;
                }
                break;
            case 3:
                game.menuSwitch = 0;
                bank.update();
                for(int i = 0; i > mapArr.size(); i++) {
                    mapArr[i].hitbox = NULL_RECT;
                }
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
        switch (game.characterSwitch) {
            case 1:
                game.draw();
                break;
            case 2:
                game2.draw2();
                break;
            case 3:
                bank.draw();
                break;
        }
        // for(int i = 0; i < mapArr.size(); i++) {
        //     DrawRectangle(mapArr[i].hitbox.x, mapArr[i].hitbox.y, mapArr[i].hitbox.width, mapArr[i].hitbox.height, RAYWHITE);
        // }
    EndDrawing();
}
void Menu::menuTextureLoad() {
    menu = LoadTexture("resources/menu.png");
    map = LoadTexture("resources/map.png");
    characterChoose = LoadTexture("resources/characterchoose.png");
    creditsTex = LoadTexture("resources/credits.png");
}