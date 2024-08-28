#include <EscapeFromAmina2/game2.hpp>

void Game2::textureLoad2() {
    m_playerNjuyse = LoadTexture("resources/EscapeFromAmina2/njuyse.png");
    m_cutscene = LoadTexture("resources/EscapeFromAmina2/cutscenes/1.png");
    m_cutscene2 = LoadTexture("resources/EscapeFromAmina2/cutscenes/2.png");
    m_cutscene3 = LoadTexture("resources/EscapeFromAmina2/cutscenes/3.png");
    m_cutscene4 = LoadTexture("resources/EscapeFromAmina2/cutscenes/4.png");
    m_bg = LoadTexture("resources/EscapeFromAmina2/basement1.png");
    m_bg2 = LoadTexture("resources/EscapeFromAmina2/basement2.png");
    m_bg3 = LoadTexture("resources/EscapeFromAmina2/bg.png");
    m_bgSecondFloor = LoadTexture("resources/EscapeFromAmina2/bgSecondFloor.png");
    // m_zamokTex = LoadTexture("resources/EscapeFromAmina2/zamok2.png");
    // m_otmichkaTex = LoadTexture("resources/EscapeFromAmina2/otmichka.png");
}

void Game2::update2() { 


    player.camera.target = {player.m_playerVec.x, 0};
    player.camera.offset = (Vector2){ 1280 /2.0f, 0};
    player.camera.rotation = 0.0f;
    player.camera.zoom = 1.0f;
    
    float minX = 0;
    float maxX = m_screen.width;

    m_cursor = GetMousePosition();

    Vector2 max = GetWorldToScreen2D((Vector2){ maxX, 720 }, player.camera);
    Vector2 min = GetWorldToScreen2D((Vector2){ minX, 0 }, player.camera);

    if (max.x < 1280) player.camera.offset.x = 1280 - (max.x - 1280 / 2);
    if (min.x > 0) player.camera.offset.x = 1280 / 2 - min.x;

    cutscene2();
}
void Game2::draw2() {
    BeginMode2D(player.camera);

    switch(player.m_switchDoors) {
        case 0:
            player.m_doorUp = {-1, -1, -1, -1};
            player.m_stairBackRec = {-1, -1, -1, -1};
            player.m_doorNextRoom = {-1, -1, -1, -1};
            player.room[0] = {0, 0, 3000, 533};
            player.room[4] = {0, 721, 3000, 1};
            player.m_stairRec = {1469, 271, 284, 265};
            m_screen = m_bg3;
            break;
        case 1:
            player.room[2] = {109, 0, 194, 720};
            player.room[3] = {293, 0, 62, 632};
            player.m_doorUp = NULL_RECT;
            player.m_otmichkaRec = {298, 419, 70, 300};
            player.m_doorBack = {1196, 246, 58, 383};
            player.m_doorNextRoom = NULL_RECT;
            m_screen = m_bg2;
            break;
        case 2:
            player.m_doorUp = {187, 207, 177, 304};
            player.m_otmichkaRec = NULL_RECT;
            player.room[2] = {0, 0, 81, 629};
            player.room[3] = {10, 646, 38, 92};
            player.m_doorNextRoom = {25, 259, 80, 330};
            m_screen = m_bg;
            break;
        case 3:
            player.m_stairBackRec = {0, 480, 46, 136};
            player.room[0] = {0, 0, 1280, 479};
            m_screen = m_bgSecondFloor;
            break;  
    }
    DrawTexture(m_screen, 0, 0, RAYWHITE);
    // DrawTexture(m_zamokTex, 500, 310, WHITE);
    // DrawTexture(m_otmichkaTex, player.m_otmichkaPos.x, player.m_otmichkaPos.y, WHITE);
    player.playerDraw();
    EndMode2D();
}
void Game2::cutscene2() {
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(m_cursor, m_nextButton) && m_nextSwitch != 5) {
        m_nextSwitch++;
    }

    switch(m_nextSwitch) {
        case 1:
            m_screen = m_cutscene;
            break;
        case 2:
            m_screen = m_cutscene2;
            break;
        case 3:
            m_screen = m_cutscene3;
            break;
        case 4:
            m_screen = m_cutscene4;
            break;
        case 5:
            m_screen = m_bg;
            player.playerUpdate();
            // player.playerUpdate();
            // player.playerDraw();
            break;
    }
}