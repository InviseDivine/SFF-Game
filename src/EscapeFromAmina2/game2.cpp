#include <EscapeFromAmina2/game2.hpp>
void Game2::escape() {
    if(CheckCollisionRecs(m_aminaCheck, player.m_playerRec)) {
        player.m_hitbox.x = 277;
        player.m_hitbox.y = 274;
        m_aminaPos.x = 160;
        m_aminaSpeed = 4;
        // printf("test");
    }
    if(player.m_playerRec.x >= 5010) {
        CloseWindow();
    }
    m_framesCounter++;
    if(m_framesCounter >= (60 / m_frameSpeed)) {
        m_framesCounter = 1;
        m_currentFrame++;
    }
    if(m_currentFrame == 2) {
        m_currentFrame = 0;
    }
    if(m_aminaPos.x >= 3000) {
        m_aminaSpeed = 6;
    }
    m_aminaPos.x += m_aminaSpeed;
    m_aminaPos.y = player.m_playerRec.y - 220;
    m_aminaR.x = m_currentFrame * m_amina.width / 2;
    m_aminaCheck = {m_aminaPos.x, m_aminaPos.y, 65, 500};
    player.m_stairRec = NULL_RECT;
    // m_aminaSpeed += 0.01;
}
void Game2::textureLoad2() {
    m_nextbutt = LoadTexture("resources/EscapeFromAmina/next.png");
    player.m_njuyse = LoadTexture("resources/EscapeFromAmina2/njuyse.png");
    m_cutscene = LoadTexture("resources/EscapeFromAmina2/cutscenes/1.png");
    m_cutscene2 = LoadTexture("resources/EscapeFromAmina2/cutscenes/2.png");
    m_cutscene3 = LoadTexture("resources/EscapeFromAmina2/cutscenes/3.png");
    m_cutscene4 = LoadTexture("resources/EscapeFromAmina2/cutscenes/4.png");
    m_bg = LoadTexture("resources/EscapeFromAmina2/basement1.png");
    m_bg2 = LoadTexture("resources/EscapeFromAmina2/basement2.png");
    m_bg3 = LoadTexture("resources/EscapeFromAmina2/bg.png");
    m_bgSecondFloor = LoadTexture("resources/EscapeFromAmina2/bgSecondFloor.png");
    m_bgAmina = LoadTexture("resources/EscapeFromAmina2/bg2.png");
    m_pyatno = LoadTexture("resources/EscapeFromAmina2/pyatno.png");
    m_forest = LoadTexture("resources/EscapeFromAmina2/escapeForest.png");
    m_otmichkaMini = LoadTexture("resources/EscapeFromAmina2/otmichkamini.png");
    m_empty = LoadTexture("resources/EscapeFromAmina/empty.png");
    m_amina = LoadTexture("resources/EscapeFromAmina2/amina.png");
    // m_zamokTex = LoadTexture("resources/EscapeFromAmina2/zamok2.png");
    // m_otmichkaTex = LoadTexture("resources/EscapeFromAmina2/otmichka.png");
}
void Game2::update2() { 
    m_cursor = GetMousePosition();

    player.camera.target = {player.m_playerVec.x, 0};
    player.camera.offset = (Vector2){ 1280 /2.0f, 0};
    player.camera.rotation = 0.0f;
    player.camera.zoom = 1.0f;
    
    float minX = 0;
    float maxX = m_screen.width;

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
                player.m_doorUp = NULL_RECT;
                player.m_stairBackRec = NULL_RECT;
                player.m_doorNextRoom = NULL_RECT;
                player.room[0] = {0, 0, 3000, 533};
                player.room[3] = {2903, 533, 127, 161};
                player.room[4] = {0, 721, 3000, 1};
                player.room[5] = {2845, 535, 56, 59};   
                player.m_stairRec = {1469, 271, 284, 265};
                player.m_escape =  {2828, 197, 118, 459};
                m_screen = m_bg3;
                break;
            case 1:
                player.room[1] = {1243, 648, 41, 82};
                player.room[2] = {109, 0, 194, 720};
                player.room[3] = {293, 0, 62, 632};
                player.room[5] = {1198, 506, 86, 135};
                player.m_doorUp = NULL_RECT;         
                player.m_otmichkaRec = {298, 419, 70, 300};
                player.m_doorBack = {1196, 246, 58, 383};
                player.m_doorNextRoom = NULL_RECT;
                m_screen = m_bg2;
                break;
            case 2:
                player.m_doorUp = {187, 207, 177, 304};
                player.m_otmichkaRec = NULL_RECT;
                player.room[1] = {0, 0, 81, 629};
                player.room[2] = {0, 0, 81, 629};
                player.room[3] = {10, 646, 38, 92};
                player.room[5] = NULL_RECT; 
                player.m_doorBack = NULL_RECT;
                player.m_doorNextRoom = {25, 259, 80, 330};
                m_screen = m_bg;
                break;
            case 3:
                player.m_stairBackRec = {0, 480, 84, 136};
                player.room[0] = {0, 0, 1280, 479};
                player.room[1] = {1243, 648, 41, 82};
                player.room[2] = {0, 0, 81, 629};
                player.room[3] = {10, 646, 38, 92};
                player.room[5] = {1198, 506, 86, 135};   
                player.m_goToAminaRoom = {134, 272, 129, 212};
                player.m_key = NULL_RECT;
                player.m_backToFloor = NULL_RECT;
                player.m_escape = NULL_RECT;
                m_screen = m_bgSecondFloor;
                break;
            case 4:        
                player.m_backToFloor = {288, 199, 131, 297};
                player.room[1] = {0, 0, 242, 720};
                player.room[2] = {907, 445, 79, 140};
                player.room[3] = {1000, 443, 160, 260};
                player.room[5] = {1198, 506, 70, 135};
                player.m_goToAminaRoom = NULL_RECT;
                player.m_key = {980, 468, 120, 238};   
                player.m_escape = NULL_RECT;
                m_screen = m_bgAmina;
                break;
            case 5:
                escape();
                isEscape = 1;
                player.room[0] = {0, 0, 5000, 147};
                player.room[1] = {0, 485, 5000, 231};
                player.room[2] = NULL_RECT;
                player.room[3] = NULL_RECT;
                player.room[4] = NULL_RECT;
                player.room[5] = NULL_RECT;
                m_screen = m_forest;
                break;
        }
        DrawTexture(m_screen, m_posScreen, 0, RAYWHITE);
        // DrawTexture(m_zamokTex, 500, 310, WHITE);
        // DrawTexture(m_otmichkaTex, player.m_otmichkaPos.x, player.m_otmichkaPos.y, WHITE);
        if(!player.isOtmichka) {
            if(player.m_switchDoors == 1) {
                DrawTexture(m_otmichkaMini, 301, 438, WHITE);
            }
        } else {
            m_otmichkaMini = m_empty;
        }
        // Почему оно так странно выглядит... Пофикшу в некст обнове
        if(player.isKey && player.m_switchDoors == 4) {
            DrawTexture(m_pyatno, 1011, 508, WHITE);
        }
        if(isEscape) {
            DrawTexturePro(m_amina,m_aminaR,{m_aminaPos.x, m_aminaPos.y, 100, 240}, {0, 0}, 0, WHITE);
        }
        // DrawRectangle(m_aminaR.x, m_aminaR.y, m_aminaR.width, m_aminaR.height, WHITE);
        player.playerDraw();
        // DrawText(TextFormat("%d",m_currentFrame),0,0,40,MAROON);
        // DrawText(TextFormat("%d",player.m_playerRec.x),0,40,40,MAROON);
        // DrawRectangle(m_aminaCheck.x, m_aminaCheck.y, m_aminaCheck.width, m_aminaCheck.height, MAROON);
    EndMode2D();
        if(m_nextSwitch != 5) {
            DrawTexture(m_nextbutt, 1111, 582, RAYWHITE);
        }
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