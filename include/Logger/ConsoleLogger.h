//
// Created by JavaChip on 24. 11. 1.
//

#ifndef CONSOLELOGGER_H
#define CONSOLELOGGER_H
#include "LoggerBase.h"

class ConsoleLogger final : public LoggerBase {
protected:
    void Log(const std::string& level, const std::string& message) override;
};

#endif //CONSOLELOGGER_H
