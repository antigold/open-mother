// OPEN-MOTHER INPUT CODE
//
// this code will have functions like
// "init_input()", "is_key_pressed()", "is_key_released()", etc.
#include "input.h"

bool is_key_pressed(int scancode){
    const Uint8* keys = SDL_GetKeyboardState(NULL);
    return keys[scancode] != 0;
}