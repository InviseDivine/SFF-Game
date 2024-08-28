#include <EscapeFromAmina2/player.hpp>
Player::Player() : m_hitbox(1280 / 2, 500, 100, 20) {}
// Этот пиздец на следующую обнову :P 
// Я реально думал, что это будет просто сделать... (Наивный)
// void Player::zamok() {
//     m_speed = 0;    

//     if(!tryingUnlock) { 
//         m_otmichkaPos.x = 660 + ((740 - 660) * sin(GetTime()));
//         m_otmichkaPos.y = 450;
//     }
    
//     if(IsKeyPressed(KEY_SPACE) && !tryingUnlock) {
//         lastUnlockTime = GetTime();
//         tryingUnlock = true;
//     }

//     if(tryingUnlock) {

//         for(auto i = 0; i < m_sticks.size(); i++) {
//             if(m_otmichkaPos.x == startLockX + (i * 30.f) + 30.f) {
//                 m_otmichkaPos.y = (450 + ((430 - 450) * (sin(lastUnlockTime - GetTime()) / 2 + 0.5)));
//             }
//             if((m_otmichka.x > startLockX + (i * 30.f) + 30.f || m_otmichka.x + m_otmichka.width < startLockX + (i * 30.f)) || 
//                 std::find(caughtSticks.begin(), caughtSticks.end(), i) != caughtSticks.end()) {
//                 continue;
//             }

//             caughtSticks.push_back(i);
//             break;
//         }

//         if(lastUnlockTime + 4 < GetTime()) {
//             tryingUnlock = false;
//         }
//     }

//     for(auto& caughtStick : caughtSticks) {
//         if(caughtStick > m_stickY + 20) {
//             caughtStick--;
//         }
//     }
    
// }
void Player::playerUpdate() {
    m_playerRec = {m_hitbox.x, m_hitbox.y, m_hitbox.width, m_hitbox.height};
    m_playerVec = {m_hitbox.x, m_hitbox.y};
    if(CheckCollisionRecs(m_stairRec, m_playerRec) && IsKeyPressed(KEY_E)) {
        m_switchDoors = secondFloor;
        m_hitbox.x = 79;
        m_hitbox.y = 530;
    }
    if(CheckCollisionRecs(m_stairRec, m_playerRec) && IsKeyPressed(KEY_E)) {
        m_switchDoors = secondFloor;
        m_hitbox.x = 79;
        m_hitbox.y = 530;
    }
    if(CheckCollisionRecs(m_playerRec, m_doorUp) && isOtmichka && IsKeyPressed(KEY_E)) {
        m_switchDoors = doorUP;
        m_hitbox.x = 169;
        m_hitbox.y = 615;
    }
    if(CheckCollisionRecs(m_playerRec, m_otmichkaRec) && IsKeyPressed(KEY_E)) {
        isOtmichka = 1;
    }
    if(CheckCollisionRecs(m_playerRec, m_doorNextRoom) && IsKeyPressed(KEY_E)) {
        m_switchDoors = doorNEXT;
        m_hitbox.x = 1107;
        m_hitbox.y = 571;
    }
    if(CheckCollisionRecs(m_playerRec, m_doorBack)  && IsKeyPressed(KEY_E)) {
        m_switchDoors = doorBACK;
        m_hitbox.x = 143;
        m_hitbox.y = 581;
    }
    if(IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
        m_speedX = m_speedX + m_speed;
    }

    if(IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
        m_speedX = m_speedX - m_speed;
    }
    if(IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) {
        m_speedZ = m_speedZ - m_speed;
    }

    if((IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))) {
        m_speedZ = m_speedZ + m_speed;
    }

    move(m_speedX, m_speedZ);

    m_speedX *= 0.70f;
    m_speedZ *= 0.70f;
    
}
void Player::playerDraw() {
    // DrawRectangle(m_doorNextRoom.x, m_doorNextRoom.y, m_doorNextRoom.width, m_doorNextRoom.height, MAROON);
    DrawRectangle(m_hitbox.x, m_hitbox.y, m_hitbox.width, m_hitbox.height, MAROON);
    for(int i = 0; i < room.size(); i++) {
        DrawRectangleLines(room[i].x,room[i].y,room[i].width,room[i].height, GREEN);
    }
    DrawRectangleLines(1469, 271, 284, 265, MAROON);
    DrawRectangle(m_playerRec.x, m_playerRec.y, m_playerRec.width, m_playerRec.height, WHITE);
    // DrawRectangle(298, 419, 60, 215, MAROON);
} 
void Player::move(float x, float y) {
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