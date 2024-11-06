//
// Created by JavaChip on 24. 10. 31.
//

#ifndef LOGGERBASE_H
#define LOGGERBASE_H

#include <mutex>

#include "ILogger.h"

class LoggerBase : public ILogger {
public:
    void Info(const std::string& message) override;
    void Debug(const std::string& message) override;
    void Warn(const std::string& message) override;
    void Error(const std::string& message) override;
    void Fatal(const std::string& message) override;

protected:
    virtual void Log(const std::string& level, const std::string& message) = 0;

private:
    virtual void LogWithMutex(const std::string& level, const std::string& message);
    std::mutex mutex;
};

#endif //LOGGERBASE_H
