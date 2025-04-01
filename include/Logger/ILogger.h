//
// Created by JavaChip on 24. 10. 31.
//

#ifndef ILOGGER_H
#define ILOGGER_H

#include <string>

class ILogger {
public:
    enum class Level {INFO, DEBUG, WARN, ERR, FATAL};

    virtual void Info(const std::string& message) = 0;
    virtual void Debug(const std::string& message) = 0;
    virtual void Warn(const std::string& message) = 0;
    virtual void Error(const std::string& message) = 0;
    virtual void Fatal(const std::string& message) = 0;

    virtual ILogger& operator<<(const std::string& message) = 0;
    virtual ILogger& operator<<(Level level) = 0;
    virtual ILogger& operator<<(std::ostream& (*manip)(std::ostream&)) = 0;

    virtual ~ILogger() = default;
};

#endif //ILOGGER_H
