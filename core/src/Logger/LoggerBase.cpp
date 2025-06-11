//
// Created by JavaChip on 24. 10. 31.
//

#include "Logger/LoggerBase.h"

#include <ostream>

void LoggerBase::Info(const std::string& message) {
    LogWithMutex(Level::INFO, message);
}

void LoggerBase::Debug(const std::string& message) {
    LogWithMutex(Level::DEBUG, message);
}

void LoggerBase::Warn(const std::string& message) {
    LogWithMutex(Level::WARN, message);
}

void LoggerBase::Error(const std::string& message) {
    LogWithMutex(Level::ERR, message);
}

void LoggerBase::Fatal(const std::string& message) {
    LogWithMutex(Level::FATAL, message);
}

std::string LoggerBase::GetLevelString(const Level &level) {
    switch (level) {
        case Level::INFO:
            return "INFO";
        case Level::DEBUG:
            return "DEBUG";
        case Level::WARN:
            return "WARN";
        case Level::ERR:
            return "ERROR";
        case Level::FATAL:
            return "FATAL";
        default:
            return "UNKNOWN";
    }
}

void LoggerBase::LogWithMutex(const Level level, const std::string &message) {
    std::lock_guard lock(mutex);
    Log(level, message);
}

LoggerBase::ThreadLocalBuffer & LoggerBase::thread_local_buffer() {
    static thread_local ThreadLocalBuffer buffer;
    return buffer;
}

ILogger & LoggerBase::operator<<(const std::string &message) {
    thread_local_buffer().buffer += message;  // 스레드별 버퍼에 메시지 추가
    return *this;
}

ILogger & LoggerBase::operator<<(const Level level) {
    thread_local_buffer().current_level = level;  // 스레드별 레벨 설정
    return *this;
}

ILogger & LoggerBase::operator<<(std::ostream &(*manip)(std::ostream &)) {
    if (manip == static_cast<std::ostream& (*)(std::ostream&)>(std::endl)) {
        auto&[buffer, currentLevel] = thread_local_buffer();
        std::lock_guard lock(mutex);
        Log(currentLevel, buffer);  // 로그 출력
        buffer.clear();  // 스레드별 버퍼 초기화
    }
    return *this;
}

void LoggerBase::Log(const Level &level, const std::string &message) {
    Log(GetLevelString(level), message);
}

