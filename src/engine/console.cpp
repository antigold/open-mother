#include "console.h"
// OPEN-MOTHER CONSOLE CODE
//
// will use unsorted maps for concommands, also will add concommands

std::unordered_map<std::string, std::function<void(std::string)>> commandmap; //command map

void init_console(){ // inits concommands
    // chatgpt time
    // 2. Insert the commands into the map
    commandmap["loadmap"] = [](const std::string& args) {
        load_map((std::string("maps/") + args).c_str());  // Calls loadmap with the argument
    };

    // 3. Another command for demonstration
    // command_map["setlevel"] = [](const std::string& args) {
    //     int level = std::stoi(args);  // Convert string to integer
    //     setlevel(level);              // Calls setlevel with the integer argument
    // };
}

// TODO - fix this mess, add whatever i put above here inside this function
void* listen_for_commands(void* arg) {
    char command[256];

    while (running) {
        printf("> ");
        fgets(command, sizeof(command), stdin);
        
        // Remove newline character from input
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "exit") == 0) {
            put(INFO_CODE,"Stopping game...");
            running = false;
            break;
        } if (strcmp(command, "loadmap") == 0) {
            unload_map();
            load_map("maps/franco.omm");
        } if (strcmp(command, "lua") == 0) {
            lua_callfunction(L, "lol", 9000); //test function, might not even work if u don't have a mod
            // printf("h");
        } if (strcmp(command, "mpause") == 0) {
            Mix_PauseMusic();
        } if (strcmp(command, "mplay") == 0) {
            Mix_ResumeMusic();
        } if (strcmp(command, "bell") == 0) {
            play_sound("sound/logo.wav");
        }
    }
    return NULL;
}



