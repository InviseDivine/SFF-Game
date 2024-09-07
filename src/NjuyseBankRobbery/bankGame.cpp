#include <NjuyseBankRobbery/bankGame.hpp>
void gameBank::run() {
    if(CheckCollisionRecs(m_copRecCheck, player.m_playerRec)) {
        player.m_hitbox.x = 97;
        player.m_hitbox.y = 300;
        m_copPos.x = 50;
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
    if(m_copPos.x >= 3000) {
        m_copSpeed = 6;
    }
    m_copPos.x += m_copSpeed;
    m_copPos.y = player.m_playerRec.y - 220;
    m_copRec.x = m_currentFrame * m_cop.width / 2;
    m_copRecCheck = {m_copPos.x, m_copPos.y, 80 / 2, 1000};
}
void gameBank::textureLoad() {
    m_cop = LoadTexture("resources/NjuyseBankRobbery/cop.png");
    player.m_njuyse = LoadTexture("resources/NjuyseBankRobbery/njuyse.png");
    m_screen = LoadTexture("resources/NjuyseBankRobbery/firstloc.png");
    m_laserRoom1 = LoadTexture("resources/NjuyseBankRobbery/twiceloc.png");
    m_endRoom = LoadTexture("resources/NjuyseBankRobbery/fourloc.png");
    m_choose = LoadTexture("resources/NjuyseBankRobbery/cutscene.png");
    m_runBG = LoadTexture("resources/NjuyseBankRobbery/bgRUN.png");
}
void gameBank::update() {
    player.camera.target = {player.m_playerRec.x, 0};
    player.camera.offset = (Vector2){ 1280 /2.0f, 0};
    player.camera.rotation = 0.0f;
    player.camera.zoom = 1.0f;

    float minX = 0;
    float maxX = m_screen.width;

    Vector2 max = GetWorldToScreen2D((Vector2){ maxX, 720 }, player.camera);
    Vector2 min = GetWorldToScreen2D((Vector2){ minX, 0 }, player.camera);

    if (max.x < 1280) player.camera.offset.x = 1280 - (max.x - 1280 / 2);
    if (min.x > 0) player.camera.offset.x = 1280 / 2 - min.x;

    m_cursor = GetMousePosition();

    if(CheckCollisionPointRec(m_cursor, m_chooseRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        player.m_hitbox.x = 97;
        player.m_hitbox.y = 564;
        player.m_recSwitch = 5;
    }
    switch(player.m_recSwitch) {
        case 1: 
            player.m_door2 = {1143, 338, 72, 283};
            m_screen = m_laserRoom1;
            player.m_door = NULL_RECT;
            player.room[0] = {0, 0, 1280, 523};
            player.room[1] = {0, 721, 1280, 1};
            player.room[2] = {0, 502, 120, 218};
            player.room[3] = {1164, 0, 118, 1000};
            player.laser[0] = {286, 0, player.m_laserWidth, 532};
            player.laser[1] = {341, 0, player.m_laserWidth, 560};
            player.laser[2] = {386, 0, player.m_laserWidth, 600};
            player.laser[3] = {286, 0, player.m_laserWidth, 69};
            player.laser[4] = {582, 567, player.m_laserWidth, 116};
            player.laser[5] = {686, 574, player.m_laserWidth, 146};
            player.laser[6] = {582, 567, player.m_laserWidth, 116};
            player.laser[7] = {868, 0, player.m_laserWidth, 537};
            player.laser[8] = {922, 0, player.m_laserWidth, 581};
            break;
        case 3:
            player.m_table = {821, 384, 274, 296};
            player.room[10] = {866, 397, 233, 290};
            m_screen = m_endRoom;
            break;
        case 4:
            player.room[10] = NULL_RECT;
            player.m_table = NULL_RECT;
            m_chooseRec = {1094, 495, 162, 175};
            m_screen = m_choose;
            break;
        case 5:
            isRun = true;
            m_screen = m_runBG;
            player.m_speed = 1.5f;
            run();
            break;
    }
    player.playerUpdate();
}
void gameBank::draw() {
    BeginMode2D(player.camera);

        DrawTexture(m_screen, 0, 0, WHITE);
        // DrawRectangle(player.room[11].x, player.room[11].y, player.room[11].width, player.room[11].height, MAROON);
        if(isRun) {
            DrawTexturePro(m_cop,m_copRec,{m_copPos.x, m_copPos.y, 80, 240}, {0, 0}, 0, WHITE);
        }
        player.playerDraw();

    EndMode2D();
}