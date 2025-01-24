// template <typename... Args>
// void lua_callfunction(lua_State* L, const std::string& funcName, Args&&... args);
#pragma once
#include <lua.hpp>
#include <string>
#include <iostream>
#include "../filesys.h"
#include "lua_registers.h"

extern lua_State* L;

template <typename T>
inline void pushArgument(lua_State* L, const T& arg) {
    put(ERROR_CODE, "LUA ERROR : Unsupported argument type!");
}

template <>
inline void pushArgument<int>(lua_State* L, const int& arg) {
    lua_pushnumber(L, arg);  // Push number (int)
}

template <>
inline void pushArgument<double>(lua_State* L, const double& arg) {
    lua_pushnumber(L, arg);  // Push number (double)
}

template <>
inline void pushArgument<std::string>(lua_State* L, const std::string& arg) {
    lua_pushstring(L, arg.c_str());  // Push string
}

template <>
inline void pushArgument<bool>(lua_State* L, const bool& arg) {
    lua_pushboolean(L, arg);  // Push boolean
}

template <typename... Args>
void lua_callfunction(lua_State* L, const std::string& funcName, Args&&... args) {
    lua_getglobal(L, funcName.c_str());  // Push the function onto the Lua stack

    //push arguments to LUA function
    (pushArgument(L, std::forward<Args>(args)), ...);

    //call the LUA function
    int result = lua_pcall(L, sizeof...(args), LUA_MULTRET, 0);  // LUA_MULTRET for multiple return values

    if (result != LUA_OK) {
        put(ERROR_CODE, "LUA ERROR : Error running function");
        put(FOLLOW_CODE, lua_tostring(L, -1));
        lua_pop(L, 1);  // pop/remove error message from the stack
        return;
    }

    // so apparently i need to keep this but it crashes lua if i keep it
    // lua_pop(L, numResults);
}

bool init_lua();
// ^ calls function from any lua file (all lua files will be combined into one state since i don't care about conflicts)
// if you want to change this, then modify code inside lua.cpp, that's where i *WILL* initialize all lua files into one state
// but most of the code will be like love or smth, you won't have to deal with conflicts unless you want to add
// mods like in garry's mod.

// usage : lua_callfunction(L, "luafunctionname",args...);
// TODO - remove that L from there since it's global