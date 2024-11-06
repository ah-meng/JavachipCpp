//
// Created by JavaChip on 24. 11. 1.
//

#include <iostream>
#include "Logger/ConsoleLogger.h"

#include <StringUtil/StringUtil.h>

void ConsoleLogger::Log(const std::string& level, const std::string& message) {
    std::cout << "[" << StringUtil::GetCurrentTimeString("%H:%M:%S") << "] " << "[" << level << "] " << message << std::endl;
}
