//
// Created by JavaChip on 24. 10. 31.
//

#ifndef ILOGGER_H
#define ILOGGER_H

#include <string>

class ILogger {
public:
    virtual void Info(const std::string& message) = 0;
    virtual void Debug(const std::string& message) = 0;
    virtual void Warn(const std::string& message) = 0;
    virtual void Error(const std::string& message) = 0;
    virtual void Fatal(const std::string& message) = 0;
    virtual ~ILogger() = default;
};

#endif //ILOGGER_H
