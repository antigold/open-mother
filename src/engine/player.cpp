// OPEN-MOTHER PLAYER CODE
//
// player stuff, you know.
#include "player.h"
#include "timer.h"
#include "input.h"
#include "map.h"
#include "logging.h"
#include "window.h"
#include <SDL2/SDL_rect.h>
#include <iostream>
#include <cstdlib>
#include <algorithm>

int speed = 200;

SDL_FRect player;
GameVector playerpos(0,0);
SDL_Texture* playertexture = nullptr;

GameVector player_corners[4] {GameVector(0,0),GameVector(0,0),GameVector(0,0),GameVector(0,0)};

void set_aabb(){
    player_corners[0] = GameVector(playerpos.getx()-30, playerpos.gety()-30);
    player_corners[1] = GameVector(playerpos.getx()+30, playerpos.gety()-30);
    player_corners[2] = GameVector(playerpos.getx()-30, playerpos.gety()+30);
    player_corners[3] = GameVector(playerpos.getx()+30, playerpos.gety()+30);
}

void init_player(){
    player = { -30.0f+(windowWidth/2), 30.0f+(windowHeight/2), 60.0f, 60.0f };
    playertexture = get_texture("swag");

    set_aabb();
}

void player_render(){
    player.x = -30.0f+(windowWidth/2); //centered
    player.y = -30.0f+(windowHeight/2); //centered
    // SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); //color
    // SDL_RenderFillRectF(renderer, &player); //draws on screen
    SDL_RenderCopyF(renderer, playertexture, nullptr, &player);
}

bool col_top(int i){
    if(player_corners[0].gety() >= map.tiles[i].corners[0].gety() &&
    player_corners[0].gety() <= map.tiles[i].corners[3].gety() &&
    player_corners[0].getx() < map.tiles[i].corners[3].getx() &&
    player_corners[3].getx() > map.tiles[i].corners[0].getx()){
        // playerpos.sety(map.tiles[i].corners[3].gety()+30);
        return true;
    }
    return false;
}
bool col_bot(int i){
    if(player_corners[3].gety() >= map.tiles[i].corners[0].gety() &&
    player_corners[3].gety() <= map.tiles[i].corners[3].gety() &&
    player_corners[0].getx() < map.tiles[i].corners[3].getx() &&
    player_corners[3].getx() > map.tiles[i].corners[0].getx()){
        return true;
    }
    return false;
}
bool col_lft(int i){
    if(player_corners[0].getx() >= map.tiles[i].corners[0].getx() &&
    player_corners[0].getx() <= map.tiles[i].corners[3].getx() &&
    player_corners[0].gety() < map.tiles[i].corners[3].gety() &&
    player_corners[3].gety() > map.tiles[i].corners[0].gety()){
        // playerpos.setx(map.tiles[i].corners[3].getx()+30);
        return true;
    }
    return false;
}
bool col_rgt(int i){
    if(player_corners[3].getx() >= map.tiles[i].corners[0].getx() &&
    player_corners[3].getx() <= map.tiles[i].corners[3].getx() &&
    player_corners[0].gety() < map.tiles[i].corners[3].gety() &&
    player_corners[3].gety() > map.tiles[i].corners[0].gety()){
        // playerpos.setx(map.tiles[i].corners[0].getx()-30);
        return true;
    }
    return false;
}

void unstuck_collision(int i){
    // i == stuckon
    float distancedown = 0; // distance left to go down to unstuck
    float distanceup = 0;
    float distanceleft = 0;
    float distanceright = 0;

    distancedown  = std::abs(player_corners[2].gety() - map.tiles[i].corners[0].gety()); // bottom left to top left
    distanceup    = std::abs(player_corners[0].gety() - map.tiles[i].corners[2].gety()); // top left to bottom left
    distanceleft  = std::abs(player_corners[0].getx() - map.tiles[i].corners[1].getx()); // top left to top right
    distanceright = std::abs(player_corners[1].getx() - map.tiles[i].corners[0].getx()); // top right to top left


    float mindistance = std::min({distancedown, distanceup, distanceleft, distanceright});

    // move in the direction of the smallest distance
    if (mindistance == distancedown) {
        // player.y += distancedown;  // move down
        playerpos.sety(playerpos.gety()-distancedown);
    } else if (mindistance == distanceup) {
        // player.y -= distanceup;    // move up
        playerpos.sety(playerpos.gety()+distanceup);
    } else if (mindistance == distanceleft) {
        // player.x -= distanceleft;  // move left
        playerpos.setx(playerpos.getx()+distanceleft);
    } else if (mindistance == distanceright) {
        // player.x += distanceright; // move right
        playerpos.setx(playerpos.getx()-distanceright);
    }

    // std::cout << "down " << distancedown << std::endl << "top " << distanceup << std::endl << "left " << distanceleft << std::endl << "right " << distanceright << std::endl;
}

bool detect_collision(int side){ // T B L R
    // std::cout << map.tiles.size();
    for(int i = 0; i < map.tiles.size(); i++){
        // std::cout << player_corners[0].gety() << " bigger than " << map.tiles[i].corners[3].gety() << " and " << player_corners[0].gety() << " smaller " << map.tiles[i].corners[0].gety() << std::endl;
        switch(side){
            case 0: //top
                if(col_top(i)){
                    unstuck_collision(i);
                    return true;
                }
                break;
            case 1: //bottom
                if(col_bot(i)){
                    unstuck_collision(i);
                    return true;
                }
                break;
            case 2: //left
                if(col_lft(i)){
                    unstuck_collision(i);
                    return true;
                }
                break;
            case 3://right
                if(col_rgt(i)){
                    unstuck_collision(i);
                    return true;
                }
                break;
        }
        
    }
    return false;
}

// TODO rename to player process
void player_move(){
    // GameVector tempplayerpos = GameVector(0,0);
    set_aabb();

    if (is_key_pressed(SDL_SCANCODE_W) && !detect_collision(0)) playerpos.sety(playerpos.gety() - (speed * dt));
    if (is_key_pressed(SDL_SCANCODE_S) && !detect_collision(1)) playerpos.sety(playerpos.gety() + (speed * dt));
    if (is_key_pressed(SDL_SCANCODE_A) && !detect_collision(2)) playerpos.setx(playerpos.getx() - (speed * dt));
    if (is_key_pressed(SDL_SCANCODE_D) && !detect_collision(3)) playerpos.setx(playerpos.getx() + (speed * dt));
}