#include <SDL2/SDL.h>

// ! CLASSES //
// ! Game 2D Vector class
class GameVector {
private:
    float x;
    float y;

public:
    GameVector(float x, float y);
    void debug();
    float getx();
    float gety();
    void setx(float x);
    void sety(float y);
};

// ! Camera class
class GameCamera {
private:
    GameVector pos;

public:
    GameCamera(GameVector pos);
    void debug();
    float getx();
    float gety();
    void setx(float x);
    void sety(float y);
};

extern GameCamera camera; // global camera class