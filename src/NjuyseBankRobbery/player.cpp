#include <NjuyseBankRobbery/player.hpp>

PlayerBank::PlayerBank() : m_hitbox(1280 / 2, 500, 100, 20) {}

void PlayerBank::playerDraw() {
    // for(int i = 0; i < room.size(); i++) {
    //     DrawRectangleLines(room[i].x,room[i].y,room[i].width,room[i].height, GREEN);
    // }
    DrawTexturePro(m_njuyse, m_njuyseAnim, {m_hitbox.x - 65, m_playerRec.y + m_playerRec.height - 230 , 240, 230}, {0, 0}, 0, WHITE);
    // for(int i = 0; i < laser.size(); i++) {
    //     DrawRectangleLines(laser[i].x,laser[i].y,laser[i].width,laser[i].height, MAROON);
    // }
    // DrawRectangle(m_playerRec.x, m_playerRec.y, m_playerRec.height, m_playerRec.width, MAROON);
    // DrawRectangle(m_hitbox.x, m_hitbox.y, m_hitbox.width, m_hitbox.height, MAROON);
}
void PlayerBank::playerUpdate() {
    m_playerRec = {m_hitbox.x, m_hitbox.y, m_hitbox.width, m_hitbox.height};
    for(auto& lasers : laser) {
        if(CheckCollisionRecs(m_playerRec, lasers)) {
            m_hitbox.x = 123;
            m_hitbox.y = 574;
        }
    }
    if(CheckCollisionRecs(m_playerRec, m_door) && IsKeyPressed(KEY_E)) {
        m_recSwitch = 1;
        m_hitbox.x = 123;
        m_hitbox.y = 574;
        for(int i = 0; i < room.size(); i++) {
            room[i]= NULL_RECT;
        }
    }
    if(CheckCollisionRecs(m_playerRec, m_door2)  && IsKeyPressed(KEY_E)) {
        m_recSwitch = 3;
        m_hitbox.x = 123;
        m_hitbox.y = 574;
        for(int i = 0; i < laser.size(); i++) {
            laser[i]= NULL_RECT;
        }
    }
    if(CheckCollisionRecs(m_playerRec, m_table)  && IsKeyPressed(KEY_E)) {
        m_recSwitch = 4;
        m_hitbox.x = 0;
        m_hitbox.y = -20;
        m_speed = 0;
        for(int i = 0; i < room.size(); i++) {
            room[i]= NULL_RECT;
        }
    }
    // player movement
    if(!IsKeyDown(KEY_A)|| !IsKeyDown(KEY_D) || !IsKeyDown(KEY_W) || !IsKeyDown(KEY_S)) {
        m_njuyseAnim.x = 0;
    }
    switch(m_animation) {
        case animationUp:
            m_njuyseAnim.y = 777;
            break;
        case animationDown:
            m_njuyseAnim.y = 518;
            break;
        case animationLeft:
            m_njuyseAnim.y = 259;
            break;
        case animationRight:
            m_njuyseAnim.y = 0;
            break;
    }
    if(IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
        framesCounter++;
        m_njuyseAnim.x = (float)currentFrame * (float)m_njuyse.width / 3;

        if (framesCounter >= (60 / 10)) { 
            framesCounter = 1;
            currentFrame++;
            if (currentFrame > 3) currentFrame = 1;
        }
        m_speedX = m_speedX + m_speed;
        m_animation = animationRight;
    }
    if(IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
        framesCounter++;
        m_njuyseAnim.x = (float)currentFrame * (float)m_njuyse.width / 3;

        if (framesCounter >= (60 / 10)) { 
            framesCounter = 1;
            currentFrame++;
            if (currentFrame > 3) currentFrame = 1;
        }
        m_speedX = m_speedX - m_speed;
        m_animation = animationLeft;    
    }
    if(IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) {
        framesCounter++;
        m_njuyseAnim.x = (float)currentFrame * (float)m_njuyse.width / 3;

        if (framesCounter >= (60 / 10)) { 
            framesCounter = 1;
            currentFrame++;
            if (currentFrame > 3) currentFrame = 1;
        }
        m_speedZ = m_speedZ - m_speed;
        m_animation = animationUp;
    }

    if((IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))) {
        framesCounter++;
        m_njuyseAnim.x = (float)currentFrame * (float)m_njuyse.width / 3;

        if (framesCounter >= (60 / 10)) { 
            framesCounter = 1;
            currentFrame++;
            if (currentFrame > 3) currentFrame = 1;
        }
        m_speedZ = m_speedZ + m_speed;
        m_animation = animationDown;
    }

    move(m_speedX, m_speedZ);

    m_speedX *= 0.70f;
    m_speedZ *= 0.70f;
}
void PlayerBank::move(float x, float y) {
    auto prevX = x;
    auto prevY = y;
    auto hitboxes = room;

    // Check for X collision
    for (auto& hitbox : hitboxes) {
        x = hitbox.clipXCollide(m_hitbox, x);
    }
    m_hitbox.move(x, 0.0f);

    // Check for Y collision
    for (auto& hitbox : hitboxes) {
        y = hitbox.clipZCollide(m_hitbox, y);
    }
    m_hitbox.move(0.0f, y);

    // Stop motion on collision
    if (prevX != x) m_speedX = 0.f;
    if (prevY != y) m_speedZ = 0.f;
} 