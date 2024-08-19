#include <EscapeFromAmina2/game2.hpp>

void Game2::textureLoad2() {
    m_cutscene = LoadTexture("resources/EscapeFromAmina2/cutscenes/1.png");
    m_cutscene2 = LoadTexture("resources/EscapeFromAmina2/cutscenes/2.png");
    m_cutscene3 = LoadTexture("resources/EscapeFromAmina2/cutscenes/3.png");
    m_cutscene4 = LoadTexture("resources/EscapeFromAmina2/cutscenes/4.png");
    m_bg = LoadTexture("resources/EscapeFromAmina2/basement1.png");
}
void Game2::update2() {
    m_cursor = GetMousePosition();
    cutscene2();
    player.playerUpdate();
}
void Game2::draw2() {
    DrawTexture(m_screen, 0, 0, RAYWHITE);
    player.playerDraw();
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
            // player.playerUpdate();
            // player.playerDraw();
            break;
    }
}