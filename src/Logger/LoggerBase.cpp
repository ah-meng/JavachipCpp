//
// Created by JavaChip on 24. 10. 31.
//

#include "Logger/LoggerBase.h"

void LoggerBase::Info(const std::string& message) {
    LogWithMutex("INFO", message);
}

void LoggerBase::Debug(const std::string& message) {
    LogWithMutex("DEBUG", message);
}

void LoggerBase::Warn(const std::string& message) {
    LogWithMutex("WARN", message);
}

void LoggerBase::Error(const std::string& message) {
    LogWithMutex("ERROR", message);
}

void LoggerBase::Fatal(const std::string& message) {
    LogWithMutex("FATAL", message);
}

void LoggerBase::LogWithMutex(const std::string& level, const std::string& message) {
    std::lock_guard lock(mutex);
    Log(level, message);
}
