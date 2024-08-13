#include <menu.hpp>
void Menu::init() {
    const int screenWidth = 1280;
    const int screenHeight = 720;
    InitWindow(screenWidth, screenHeight, "SFF Game 0.1");
    InitAudioDevice();
    menu = LoadTexture("resources/SFFMenu.png");
    menuScreen = menu;
    game.door = LoadSound("resoucres/EscapeFromAmina/door.ogg");
    characterChoose = LoadTexture("resources/characterchoose.png");
    SetTargetFPS(60);
    Rectangle test = {(float)0,(float)0,(float)100,(float)100};
    Game::m_texture.textureLoad();
    while (!WindowShouldClose()) {
    cursor = GetMousePosition();
        PlaySound(game.door);
        this->render();   
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(cursor, play)) {
            game.menuSwitch = 1;
        }
        switch(game.menuSwitch) {
            // case 1:
            //     game.isGameEnd = 0;
            //     cut.cutscene();
            //     break;
            case 0:
                menuScreen = menu;
                play = {8, 187, 176, 72};
                codes = {41, 258, 138, 48};
                credits = {75, 333, 135, 35};
                break;
            case 1:
                menuScreen = characterChoose;
                play = NULL_RECT;
                codes = NULL_RECT;
                credits = NULL_RECT;
                for(auto& character : characters) {
                    if(CheckCollisionPointRec(cursor, character.hitbox) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                        game.characterSwitch = character.id;
                    }
                }
                break;
        }
        if(game.characterSwitch == 0) {
            game.menuSwitch = 0;
            game.characterSwitch = -1;
        }
        switch(game.characterSwitch) {
            case -1:
                break;
            case BACK:
                break;
            case NJUYSE:
                game.isGameEnd = 0;
                cut.cutscene();
                break;
        }
    }
    CloseWindow();
    UnloadSound(game.door);
    CloseAudioDevice(); 
}
void Menu::render() {
    BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(menuScreen, 0, 0, WHITE);
        DrawRectangle(421, 258, 84, 89, MAROON);
        switch(game.characterSwitch) {
            case 1:
                game.draw();
                break;
        }
    EndDrawing();
}