// OPEN-MOTHER INPUT CODE
//
// this code will have functions like
// "init_input()", "is_key_pressed()", "is_key_released()", etc.
#include "input.h"

// * Checks if a key was pressed, scancode should be something like "SDL_SCANCODE_X"
bool is_key_pressed(int scancode){
    const Uint8* keys = SDL_GetKeyboardState(NULL); //gets keys only when asks for keypress, this way we don't check every frame for a keypress
    return keys[scancode] != 0;
}