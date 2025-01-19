#include "console.h"
// OPEN-MOTHER CONSOLE CODE
//
// will use unsorted maps for concommands, also will add concommands

std::unordered_map<std::string, std::function<void(std::string)>> commandmap; //command map

void console_init(){ // inits concommands
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

void* listen_for_commands(void* arg) {
    char command[256];

    while (running) {
        printf("Enter a command: ");
        fgets(command, sizeof(command), stdin);
        
        // Remove newline character from input
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "exit") == 0) {
            put(INFO_CODE,"Stopping game...");
            running = false;
            break;
        } if (strcmp(command, "loadmap") == 0) {
            unload_map();
            load_map("maps/yna.omm");
        } else {
            printf("Unknown command: %s\n", command);
        }
    }
    

    printf("returning");
    return NULL;
}



