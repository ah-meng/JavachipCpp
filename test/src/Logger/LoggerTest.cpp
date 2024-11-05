//
// Created by JavaChip on 24. 11. 1.
//

#include "Logger/LoggerBase.h"
#include <gtest/gtest.h>
#include <string>

// TestLogger는 LoggerBase를 상속하여 Log 메서드를 재정의한 테스트용 클래스입니다.
class TestLogger final : public LoggerBase {
public:
    void Log(const std::string& level, const std::string& message) override {
        lastLevel = level;
        lastMessage = message;
    }

    std::string lastLevel;
    std::string lastMessage;
};

// 각 로그 메서드가 올바른 레벨과 메시지를 기록하는지 테스트
TEST(LoggerBaseTest, InfoLogTest) {
    TestLogger logger;
    logger.Info("This is an info message");
    EXPECT_EQ(logger.lastLevel, "INFO");
    EXPECT_EQ(logger.lastMessage, "This is an info message");
}

TEST(LoggerBaseTest, DebugLogTest) {
    TestLogger logger;
    logger.Debug("This is a debug message");
    EXPECT_EQ(logger.lastLevel, "DEBUG");
    EXPECT_EQ(logger.lastMessage, "This is a debug message");
}

TEST(LoggerBaseTest, WarnLogTest) {
    TestLogger logger;
    logger.Warn("This is a warning message");
    EXPECT_EQ(logger.lastLevel, "WARN");
    EXPECT_EQ(logger.lastMessage, "This is a warning message");
}

TEST(LoggerBaseTest, ErrorLogTest) {
    TestLogger logger;
    logger.Error("This is an error message");
    EXPECT_EQ(logger.lastLevel, "ERROR");
    EXPECT_EQ(logger.lastMessage, "This is an error message");
}

TEST(LoggerBaseTest, FatalLogTest) {
    TestLogger logger;
    logger.Fatal("This is a fatal message");
    EXPECT_EQ(logger.lastLevel, "FATAL");
    EXPECT_EQ(logger.lastMessage, "This is a fatal message");
}