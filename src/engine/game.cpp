// OPEN-MOTHER GAME CODE
//
// "run_game_loop()","update_game_state()",etc...
// player = { 300.0f, 200.0f, 32.0f, 32.0f } i need this for later

#include "game.h"
#include "window.h"

// Game 2D Vector class
// GameVector::GameVector() {

// };

void GameVector::debug(){
    printf("X:%f - Y:%f", x,y);
};

float GameVector::getrelativex(){
    return x - camera.getx() + (windowWidth/2); //adds centering and position from camera
};

float GameVector::getrelativey(){
    return y - camera.gety() + (windowHeight/2); //adds centering and position from camera
};

float GameVector::getx(){
    return x;
};

float GameVector::gety(){
    return y;
};

void GameVector::setx(float x){
    this->x = x;
};

void GameVector::sety(float y){
    this->y = y;
};

// Game camera class
GameCamera::GameCamera(GameVector pos) : pos(pos){
    
};

void GameCamera::debug(){
    printf("X:%f - Y:%f", pos.getx(), pos.gety());
};

void GameCamera::setpos(GameVector newpos){
    pos.setx(newpos.getx());
    pos.sety(newpos.gety());
}

float GameCamera::getx(){
    return pos.getx();
};

float GameCamera::gety(){
    return pos.gety();
};

void GameCamera::setx(float x){
    pos.setx(x);
};

void GameCamera::sety(float y){
    pos.sety(y);
};
