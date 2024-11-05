//
// Created by JavaChip on 24. 10. 31.
//

#include <iostream>
#include <chrono>
#include <iomanip>
#include <ctime>
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

std::string LoggerBase::GetCurrentTimeString(const std::string& format) {
    // 현재 시간 가져오기
    const auto now = std::chrono::system_clock::now();
    const std::time_t now_time = std::chrono::system_clock::to_time_t(now);

    // 시간 형식을 맞춰서 출력하기 위해 tm 구조체 사용
    const std::tm local_time = *std::localtime(&now_time);

    // 스트림에 원하는 형식으로 출력
    std::stringstream ss;
    ss << std::put_time(&local_time, format.c_str());

    return ss.str();
}

void LoggerBase::LogWithMutex(const std::string& level, const std::string& message) {
    std::lock_guard lock(mutex);
    Log(level, message);
}
