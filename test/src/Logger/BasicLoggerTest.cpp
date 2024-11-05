//
// Created by JavaChip on 24. 11. 5.
//

#include "Logger/FileLogger.h"  // BasicFileLogger 헤더 파일 포함
#include <gtest/gtest.h>
#include <fstream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

class BasicFileLoggerTest : public ::testing::Test {
protected:
    void SetUp() override {
        // 기본 테스트 로그 디렉터리 설정
        testLogDirectory = "test_logs";
        if (!fs::exists(testLogDirectory)) {
            fs::create_directories(testLogDirectory);
        }

        // 테스트 시작 전에 로그 파일 삭제
        ClearLogFiles();
    }

    void TearDown() override {
        // 테스트 후 로그 파일 삭제
        ClearLogFiles();
    }

    // 로그 파일을 모두 삭제하는 함수
    void ClearLogFiles() {
        if (fs::exists(testLogDirectory)) {
            for (const auto& entry : fs::directory_iterator(testLogDirectory)) {
                if (is_directory(entry.path())) {
                    // 디렉토리가 있으면 먼저 비우기
                    remove_all(entry.path());  // 디렉터리 내 모든 파일 및 서브 디렉터리 삭제
                } else {
                    // 파일 삭제
                    fs::remove(entry.path());
                }
            }
        }
    }

    static std::string GenerateFileName() {
        return "log_" + GenerateDateString();
    }

    static std::string GenerateDateString() {
        return GetCurrentTimeString("%Y-%m-%d");
    }

    static std::string GetCurrentTimeString(const std::string& format) {
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

    // 마지막으로 기록된 로그 파일의 마지막 라인을 읽는 함수
    static std::string ReadLastLog(const std::string& logPath) {
        std::ifstream logFile(fs::u8path(logPath) / GenerateFileName());
        std::string lastLine, line;
        while (std::getline(logFile, line)) {
            if (!line.empty())
                lastLine = line;
        }
        return lastLine;
    }

    // 가장 최근에 생성된 로그 파일의 경로를 반환하는 함수
    std::string GetLatestLogFilePath() {
        std::string latestLogFile;
        for (const auto& entry: fs::directory_iterator(testLogDirectory)) {
            latestLogFile = entry.path().string();
        }
        return latestLogFile;
    }

    std::string testLogDirectory;
};

// 한글 경로 테스트
TEST_F(BasicFileLoggerTest, KoreanPathTest) {
    std::string koreanLogDirectory = testLogDirectory + "/" + "로그_테스트"; // 한글 경로


    BasicFileLogger logger(koreanLogDirectory);
    logger.Info("Test log in Korean directory");

    std::string lastLog = ReadLastLog(koreanLogDirectory);
    EXPECT_TRUE(lastLog.find("[INFO]") != std::string::npos);
    EXPECT_TRUE(lastLog.find("Test log in Korean directory") != std::string::npos);
}

// 일본어 경로 테스트
TEST_F(BasicFileLoggerTest, JapanesePathTest) {
    std::string japaneseLogDirectory = testLogDirectory + "/" + "ログテスト"; // 일본어 경로

    BasicFileLogger logger(japaneseLogDirectory);
    logger.Info("Test log in Japanese directory");

    std::string lastLog = ReadLastLog(japaneseLogDirectory);
    EXPECT_TRUE(lastLog.find("[INFO]") != std::string::npos);
    EXPECT_TRUE(lastLog.find("Test log in Japanese directory") != std::string::npos);
}

// 중국어 경로 테스트
TEST_F(BasicFileLoggerTest, ChinesePathTest) {
    std::string chineseLogDirectory = testLogDirectory + "/" + "日志测试"; // 중국어 경로

    BasicFileLogger logger(chineseLogDirectory);
    logger.Info("Test log in Chinese directory");

    std::string lastLog = ReadLastLog(chineseLogDirectory);
    EXPECT_TRUE(lastLog.find("[INFO]") != std::string::npos);
    EXPECT_TRUE(lastLog.find("Test log in Chinese directory") != std::string::npos);
}
