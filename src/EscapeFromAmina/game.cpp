#include <EscapeFromAmina/game.hpp>
#include <iostream>
#define NULL_RECT {0, 0, 0, 0}
void Game::update() {
    cursor = GetMousePosition(); 
    for(auto& event : events) {
        if(CheckCollisionPointRec(cursor, event.hitbox) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            m_switchRoom = event.room;
        }
    }
    switch(m_switchRoom) {
        case BED:
            m_texture.m_backbuttonScreen = m_texture.m_backbuttonTex;
            m_texture.m_onScreen = m_texture.m_bed;
            events[ROOM].hitbox = {100, 600, 200, 100};
            events[BED].hitbox = NULL_RECT;
            events[SHKAF].hitbox = NULL_RECT;
            events[TYMBOCHKA].hitbox = NULL_RECT;
            break;
        case SHKAF:
            m_texture.m_backbuttonScreen = m_texture.m_backbuttonTex;
            m_texture.m_onScreen = m_texture.m_schkaf;
            events[ROOM].hitbox = {100, 600, 200,100};
            events[BED].hitbox = NULL_RECT;
            events[SHKAF].hitbox = NULL_RECT;
            events[TYMBOCHKA].hitbox = NULL_RECT;
            events[KEY].hitbox = {600,150,50,50};
            break;
        case TYMBOCHKA:
            m_texture.m_backbuttonScreen = m_texture.m_backbuttonTex;
            m_texture.m_onScreen = m_texture.m_tymbochka;
            events[ROOM].hitbox = {100, 600, 200, 100};
            events[BED].hitbox = NULL_RECT;
            events[SHKAF].hitbox = NULL_RECT;
            events[TYMBOCHKA].hitbox = NULL_RECT;
            break;
        case KEY:
            m_texture.m_onScreen = m_texture.m_outsideRoom;
            m_texture.m_backbuttonScreen = m_texture.m_backempty;
            events[ROOM].hitbox = NULL_RECT;
            events[BED].hitbox = NULL_RECT;
            events[SHKAF].hitbox = NULL_RECT;
            events[TYMBOCHKA].hitbox = NULL_RECT;
            events[KEY].hitbox = NULL_RECT;
            isKeyGet = 1;
            this->outsideRoom();
            break;
        default:
            m_texture.m_backbuttonScreen = m_texture.m_backempty;
            m_texture.m_onScreen = m_texture.m_room;
            events[ROOM].hitbox = NULL_RECT;
            events[BED].hitbox = {710.0, 270.0, 350.0, 150.0};
            events[SHKAF].hitbox = {100.0, 150.0, 242.0, 425.0};
            events[TYMBOCHKA].hitbox = {500.0, 200.0, 200.0, 200.0};
            break; 
    }
}
void Game::outsideRoom() {
    if(!m_isGetTime) {
        m_lastTime = GetTime();
        m_isGetTime = 1;
    }
        if(isKeyGet) {
            switch(m_currentScene) {
                case 2:
                    m_texture.m_onScreen = m_texture.m_outsideRoom2;
                    break;
                case 3:
                    m_texture.m_onScreen = m_texture.m_outsideRoom3;
                    break;
                case 4:
                    m_texture.m_onScreen = m_texture.m_outsideRoom4;
                    break;
                case 5:
                    m_texture.m_onScreen = m_texture.m_outsideRoom5;
                    break;
                case 6:
                    m_texture.m_onScreen = m_texture.m_outsideRoom6;
                    break;
                case 7:
                    isKeyGet = true;
                    m_texture.m_onScreen = m_texture.m_outsideRoom6;
                    m_dodge = {150,457,150,100};
                    m_dodge2 = {553,461,150,100};
                    m_gameOver = {-1, -1, -1, -1};
                    break;
                case 8:
                    m_texture.m_onScreen = m_texture.m_outsideRoom7;
                    m_dodge = NULL_RECT;
                    m_dodge2 = NULL_RECT;
                    this->outsideHouse();
                    break;
                case 9:
                    m_texture.m_onScreen = m_texture.m_gameOver;
                    m_dodge = {-1, -1, -1, -1};
                    m_dodge2 = {-1, -1, -1, -1};
                    m_gameOver = {524,521,350,50};
                    isKeyGet = false;
                    break;  
            } 
            if(m_currentScene != 6 && m_currentScene < 6) {
                if(GetTime() >= m_lastTime + 3) {
                    m_lastTime = GetTime();
                    m_currentScene++;
                }
            } else {
                m_dodge = {150,457,150,100};
                m_dodge2 = {553,461,150,100};
            }
        }
    if(CheckCollisionPointRec(cursor, m_gameOver) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        m_currentScene = 7;
    }
    if(CheckCollisionPointRec(cursor, m_dodge) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        m_currentScene = 9;
    }
    if(CheckCollisionPointRec(cursor, m_dodge2) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        m_currentScene = 8;
    }
}
void Game::outsideHouse() {
    if(!m_isGetTime2) {
        m_lastTime = GetTime();
        m_isGetTime2 = 1;
    }
    if(m_currentframe != 7 && m_currentframe < 7) {
        if(GetTime() >= m_lastTime + 3) {
            m_lastTime = GetTime();
            m_currentframe++;
        }
    }
    switch(m_currentframe) {
        case 2:
            m_texture.m_onScreen = m_texture.m_outsideRoom8;
            break;
        case 3:
            m_texture.m_onScreen = m_texture.m_outsideRoom9;
            break;
        case 4:
            m_texture.m_onScreen = m_texture.m_outsideHouse;
            break;
        case 5:
            m_texture.m_onScreen = m_texture.m_outsideHouse2;
            break;
        case 6:
            m_texture.m_onScreen = m_texture.m_outsideHouse3;
            break;
        case 7:
            this->outsideChoose();
            break;
    }
}
void Game::outsideChoose() {
        for(auto& outside : eventsOutside) {
            if(CheckCollisionPointRec(cursor, outside.hitbox) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                m_currentRock = outside.room;
            }
        }
        switch(m_currentRock) {
        case 0:
            m_texture.m_onScreen = m_texture.m_outsideHouse4;
            eventsOutside[ROCK1].hitbox = {330,310,150,120};
            eventsOutside[ROCK2].hitbox = {520,330,150,120};
            eventsOutside[ROCK3].hitbox = {700,310,150,120};
            eventsOutside[ROCK4].hitbox = {880,330,150,120};
            break;
        case 1:
            if(!m_isGetTimeOut2) {
                m_lastTime2 = GetTime();
                m_isGetTimeOut2 = 1;
            }
            if(GetTime() >= m_lastTime2 + 3) {
                m_switchRock++;
                m_lastTime2 = GetTime();
            }
            this->outsideHouse2();
            break;
        case 2:
            this->finalCutscene();
            break;
        case 3:
            if(!m_isGetTimeOut) {
                m_lastTime2 = GetTime();
                m_isGetTimeOut = 1;
            }
            if(GetTime() >= m_lastTime2 + 3) {
                m_switchRock++;
                m_lastTime2 = GetTime();
            }
            this->outsideHouse2();
            break;
        case 4:
            this->finalCutscene();
            break;
    }
}
void Game::outsideHouse2() {
    eventsOutside[ROCK1].hitbox = NULL_RECT;
    eventsOutside[ROCK2].hitbox = NULL_RECT;
    eventsOutside[ROCK3].hitbox = NULL_RECT;
    eventsOutside[ROCK4].hitbox = NULL_RECT;
    switch(m_switchRock) {
    case 1:
        m_texture.m_onScreen = m_texture.m_outsideHouse5;
        break;
    case 2:
        m_texture.m_onScreen = m_texture.m_outsideHouse6;
        break;
    case 3:
        m_texture.m_onScreen = m_texture.m_gameOver;
        m_gameOver2 = {524,521,350,50};
        if(CheckCollisionPointRec(cursor, m_gameOver2) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            m_currentRock = 0;
            m_gameOver2 = NULL_RECT;
            m_switchRock = 1;
        }
        break;
    }
}
void Game::finalCutscene() {
    eventsOutside[ROCK1].hitbox = NULL_RECT;
    eventsOutside[ROCK2].hitbox = NULL_RECT;
    eventsOutside[ROCK3].hitbox = NULL_RECT;
    eventsOutside[ROCK4].hitbox = NULL_RECT;
    if(!m_isGetTimeOut3) {
        m_lastTime3 = GetTime();
        m_isGetTimeOut3 = 1;
    }
    if(GetTime() >= m_lastTime3 + 3 && m_lastCutscene != 6 ) {
        m_lastCutscene++;
        m_lastTime3 = GetTime();
    }
    switch(m_lastCutscene) {
    case 0:
        return;
        break;
    case 1:
        m_texture.m_onScreen = m_texture.m_outsideHouse5;
        break;
    case 2:
        m_texture.m_onScreen = m_texture.m_outsideHouse6;
        break;
    case 3:
        m_texture.m_onScreen = m_texture.m_outsideHouse7;
        break;
    case 4:
        m_texture.m_onScreen = m_texture.m_outsideHouse8;
        break;
    case 5:
        m_texture.m_onScreen = m_texture.m_home;
        break;
    case 6:
        m_texture.m_onScreen = m_texture.m_backempty;
        menuSwitch = 0;
        characterSwitch = -1;
        plusplus = 0;
        m_switchRoom = 0;
        m_switchRock = 1;
        m_currentRock = 0;
        m_currentScene = 0;
        isKeyGet = 0;
        m_currentframe = 1;
        m_lastTime = 0;
        m_lastTime2 = 0;
        m_lastTime3 = 0;
        isGameEnd = 1;
        break;
    }
    if(isGameEnd) {
        m_lastCutscene = 0;
        isGameEnd = 0;
    }
}
void Game::draw() {
    DrawTexture(Game::m_texture.m_onScreen,0,0,RAYWHITE);
    if(plusplus != 9) {
        DrawTexture(Game::m_texture.m_nextbutton, 1111, 582, RAYWHITE);
    }
    DrawTexture(Game::m_texture.m_backbuttonScreen,50,500,RAYWHITE); 
    // DrawText(TextFormat("%i",menuSwitch), 0, 0, 20, MAROON);
    // DrawText(TextFormat("%i",m_lastCutscene), 0, 20, 20, MAROON);
    // DrawText(TextFormat("%i",m_switchRoom), 0, 20, 20, MAROON);
}