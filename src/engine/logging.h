#pragma once
#include <iostream>
#include <string>

enum LogLevel {
    INFO_CODE,
    WARN_CODE,
    ERROR_CODE,
    FOLLOW_CODE
};

void put(LogLevel level, const std::string& message);