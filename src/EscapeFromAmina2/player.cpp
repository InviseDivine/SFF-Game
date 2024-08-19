#include <EscapeFromAmina2/player.hpp>
Player::Player() : m_hitbox(0, 0, 100, 100) {}

void Player::playerUpdate() {
    if(IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
        // m_direction = RIGHT;
        m_speedX = m_speedX + 1.5;
    }

    if(IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
        // m_direction = LEFT;
        m_speedX = m_speedX - 1.5;
    }
    if(IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) {
        m_speedZ = m_speedZ - 1.5;
    }

    if((IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))) {
        m_speedZ = m_speedZ + 1.5;
    }

    move(m_speedX, m_speedZ);

    m_speedX *= 0.70f;
    m_speedZ *= 0.70f;
    
}
void Player::playerDraw() {
    DrawRectangle(m_hitbox.x, m_hitbox.y, m_hitbox.width, m_hitbox.height, MAROON);

    for(int i = 0; i<2; i++) {
        DrawRectangle(room[i].x,room[i].y,room[i].width,room[i].height, MAROON);
    }
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

    // printf("x: %f ", x);
    // printf("\n y: %f", y);
} 