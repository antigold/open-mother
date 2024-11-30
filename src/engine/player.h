#include <SDL2/SDL.h>

const int speed = 200;
extern SDL_FRect player; // player square, change this to an object soon

void init_player();
void player_move();