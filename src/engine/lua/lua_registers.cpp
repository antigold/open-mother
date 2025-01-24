#include "lua_registers.h"

int set_speed(lua_State* L) {
    if (lua_isnumber(L, -1)) {
        speed = lua_tonumber(L, -1);  // Update speed in C++
    } else {
        put(ERROR_CODE, "LUA ERROR : speed should be a number");
    }
    return 0;  // No return value
}
