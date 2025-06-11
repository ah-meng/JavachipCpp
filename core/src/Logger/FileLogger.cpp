//
// Created by JavaChip on 24. 11. 1.
//

#include <string>
#include <filesystem>
#include "Logger/FileLogger.h"

#include <StringUtil/StringUtil.h>

namespace fs = std::filesystem;

BasicFileLogger::BasicFileLogger(const std::string& logDirectory): logDirectory(logDirectory) {
    if (fs::path logDir = fs::u8path(logDirectory); !exists(logDir))
        create_directory(logDir);

    UpdateLogFile();
}

void BasicFileLogger::Log(const std::string& level, const std::string& message) {
    if (IsDateChanged()) {
        UpdateLogFile();
    }

    const fs::path fileName = GenerateFileName();
    const fs::path filePath = fs::u8path(logDirectory) / fileName;

    std::ofstream logFile(filePath, std::ios::app);
    if (!logFile.is_open()) throw std::runtime_error("Could not open log file.");

    logFile << "[" << StringUtil::GetCurrentTimeString("%H:%M:%S") << "] " << "[" << level << "] " << message << std::endl;
}

std::string BasicFileLogger::GenerateFileName() {
    return "log_" + GenerateDateString();
}

bool BasicFileLogger::IsDateChanged() const {
    return currentDate != GenerateDateString();
}

std::string BasicFileLogger::GenerateDateString() {
    return StringUtil::GetCurrentTimeString("%Y-%m-%d");
}

void BasicFileLogger::UpdateLogFile() {
    if (logFile.is_open())
        logFile.close();

    const fs::path fileName = GenerateFileName();
    const fs::path filePath = fs::u8path(logDirectory) / fileName;

    logFile.open(filePath, std::ios::app);
    if (!logFile.is_open())
        throw std::runtime_error("Could not open log file : " + fileName.string());

    currentDate = GenerateDateString();
}
