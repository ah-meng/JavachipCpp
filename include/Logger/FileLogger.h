//
// Created by JavaChip on 24. 11. 1.
//

#ifndef FILELOGGER_H
#define FILELOGGER_H

#include <fstream>
#include "LoggerBase.h"

class BasicFileLogger final : public LoggerBase {
public:
    explicit BasicFileLogger(const std::string& logDirectory);

protected:
    void Log(const std::string& level, const std::string& message) override;

private:
    std::string logDirectory;
    std::ofstream logFile;

    std::string currentDate;
    bool IsDateChanged() const;
    void UpdateLogFile();
    static std::string GenerateFileName();
    static std::string GenerateDateString();
};


#endif //FILELOGGER_H
