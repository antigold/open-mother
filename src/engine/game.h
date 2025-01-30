#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <unordered_map>
#include <string>

// relative xy = used in rendering
// xy = absolute positions
// ! CLASSES //
// ! Game 2D Vector class
class GameVector {
private:
    float x;
    float y;

public:
    GameVector(float xpos, float ypos) : x(xpos), y(ypos) {};
    void debug();
    float getrelativex();
    float getrelativey();
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
    void setpos(GameVector newpos);
    float getx();
    float gety();
    void setx(float x);
    void sety(float y);
};

extern GameCamera camera; // global camera class

extern std::unordered_map<std::string, SDL_Texture*> textures; // textures - usage: textures["texturename"]

//LOADS TEXTURES
SDL_Texture* load_texture(const char* path, SDL_Renderer* renderer);

//ADDS TEXTURE - USAGE: add_texture("texturename", "texturepath", renderer);
void add_texture(const std::string& name, const char* path, SDL_Renderer* renderer);

//GETS TEXTURE - USAGE: get_texture("texturename");
SDL_Texture* get_texture(const std::string& name);
