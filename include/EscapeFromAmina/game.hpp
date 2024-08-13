#pragma once
#include <raylib.h>
#include "textureload.hpp"
#include <vector>
typedef enum screen { ROOM = 0, SHKAF, TYMBOCHKA, BED, KEY
} screen;
typedef enum outside { ROCK1 = 1, ROCK2 , ROCK3, ROCK4
} 
outside;
struct HitboxEvent {
    Rectangle hitbox;
    int room;
};
class Game {
private:
    Vector2 cursor;
    bool isKeyGet = 0;
    int m_switchRoom = 0;
    std::vector<HitboxEvent> events = {
        {{-1, -1, -1, -1}, 0}, 
        {{100.0, 150.0, 242.0, 425.0}, 1}, 
        {{500.0, 200.0, 200.0, 200.0}, 2}, 
        {{710.0, 270.0, 350.0, 150.0}, 3},
        {{-1, -1, -1, -1}, 4},
        {{-1, -1, -1, -1}, 5}
    };
    std::vector<HitboxEvent> eventsOutside = {
        {{-1, -1, -1, -1}, 0}, 
        {{-1, -1, -1, -1}, 1}, 
        {{-1, -1, -1, -1}, 2}, 
        {{-1, -1, -1, -1}, 3},
        {{-1, -1, -1, -1}, 4},
        {{-1, -1, -1, -1}, 5}
    };
    Rectangle m_dodge = {-1, -1, -1, -1};
    Rectangle m_dodge2 = {-1, -1, -1, -1};
    Rectangle m_gameOver = {-1, -1, -1, -1};
    Rectangle m_gameOver2 = {-1, -1, -1, -1};
    int m_lastTime = 0;
    int m_lastTime2 = 0;
    int m_lastTime3 = 0;
    int m_currentScene = 1;
    int m_currentframe = 1;
    int m_currentRock = 0;
    int m_switchRock = 1;
    int m_lastCutscene = 1;
    bool m_isGetTime;
    bool m_isGetTime2;
    bool m_isGetTimeOut = 0;
    bool m_isGetTimeOut2;
    bool m_isGetTimeOut3;
public:
    bool isGameEnd = 0;
    static inline int plusplus = 0;
    static inline  int menuSwitch = 0;
    static inline int characterSwitch = -1;
    Sound door;
    inline static texture m_texture;
    void draw();
    void update();
    void outsideRoom();
    void outsideHouse();
    void outsideChoose();
    void outsideHouse2();
    void finalCutscene();
};