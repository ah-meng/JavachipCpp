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
    ILogger & operator<<(const std::string &message) override;
    ILogger & operator<<(Level level) override;
    ILogger & operator<<(std::ostream &(*manip)(std::ostream &)) override;

protected:
    void Log(const Level &level, const std::string &message);
    virtual void Log(const std::string& level, const std::string& message) = 0;

private:
    [[nodiscard]] static std::string GetLevelString(const Level& level) ;

    virtual void LogWithMutex(Level level, const std::string& message);
    std::mutex mutex;
    struct ThreadLocalBuffer {
        std::string buffer;  // 스레드별 버퍼
        Level current_level = Level::INFO;  // 스레드별 로깅 수준
    };
    // 스레드 로컬 버퍼를 반환
    static ThreadLocalBuffer& thread_local_buffer();
};

#endif //LOGGERBASE_H
