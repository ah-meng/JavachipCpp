//
// Created by JavaChip on 24. 11. 1.
//

#include "Logger/LoggerBase.h"
#include <gtest/gtest.h>
#include <string>
#include <thread>

// TestLogger는 LoggerBase를 상속하여 Log 메서드를 재정의한 테스트용 클래스입니다.
class TestLogger final : public LoggerBase {
public:
    void Log(const std::string& level, const std::string& message) override {
        // 각 스레드 별로 독립적인 로그 상태를 유지
        thread_local_log().lastLevel = level;
        thread_local_log().lastMessage = message;
    }
    // 스레드에 따라 독립적인 로그 상태를 유지하기 위한 구조체
    struct LogData {
        std::string lastLevel;
        std::string lastMessage;
    };

    // 스레드 독립 데이터를 제공
    static LogData& thread_local_log() {
        static thread_local LogData logData;
        return logData;
    }

    // 마지막 로그 데이터 반환(스레드 로컬)
    static LogData& GetLastLogData() {
        return thread_local_log();
    }

};

// 각 로그 메서드가 올바른 레벨과 메시지를 기록하는지 테스트
TEST(LoggerBaseTest, InfoLogTest) {
    TestLogger logger;
    logger.Info("This is an info message");

    auto& logData = TestLogger::GetLastLogData();

    EXPECT_EQ(logData.lastLevel, "INFO");
    EXPECT_EQ(logData.lastMessage, "This is an info message");
}

TEST(LoggerBaseTest, DebugLogTest) {
    TestLogger logger;
    logger.Debug("This is a debug message");

    auto& logData = TestLogger::GetLastLogData();

    EXPECT_EQ(logData.lastLevel, "DEBUG");
    EXPECT_EQ(logData.lastMessage, "This is a debug message");
}

TEST(LoggerBaseTest, WarnLogTest) {
    TestLogger logger;
    logger.Warn("This is a warning message");

    auto& logData = TestLogger::GetLastLogData();

    EXPECT_EQ(logData.lastLevel, "WARN");
    EXPECT_EQ(logData.lastMessage, "This is a warning message");
}

TEST(LoggerBaseTest, ErrorLogTest) {
    TestLogger logger;
    logger.Error("This is an error message");

    auto& logData = TestLogger::GetLastLogData();

    EXPECT_EQ(logData.lastLevel, "ERROR");
    EXPECT_EQ(logData.lastMessage, "This is an error message");
}

TEST(LoggerBaseTest, FatalLogTest) {
    TestLogger logger;
    logger.Fatal("This is a fatal message");

    auto& logData = TestLogger::GetLastLogData();

    EXPECT_EQ(logData.lastLevel, "FATAL");
    EXPECT_EQ(logData.lastMessage, "This is a fatal message");
}

TEST(LoggerBaseTest, StreamOperatorTest) {
    TestLogger logger;
    logger << "This is a message" << std::endl;

    auto& logData = TestLogger::GetLastLogData();

    EXPECT_EQ(logData.lastLevel, "INFO");
    EXPECT_EQ(logData.lastMessage, "This is a message");

    logger << ILogger::Level::DEBUG << "This is a debug message" << std::endl;

    logData = TestLogger::GetLastLogData();

    EXPECT_EQ(logData.lastLevel, "DEBUG");
    EXPECT_EQ(logData.lastMessage, "This is a debug message");
}

TEST(LoggerBaseTest, StreamOperatorInMultiThreadTest) {
    TestLogger logger;
    std::thread t1([&logger] {
        logger << "This is a message" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        auto& logData = TestLogger::GetLastLogData();

        EXPECT_EQ(logData.lastLevel, "INFO");
        EXPECT_EQ(logData.lastMessage, "This is a message");
    });
    std::thread t2([&logger] {
        logger << ILogger::Level::DEBUG << "This is a debug message" << std::endl;

        auto& logData = TestLogger::GetLastLogData();

        EXPECT_EQ(logData.lastLevel, "DEBUG");
        EXPECT_EQ(logData.lastMessage, "This is a debug message");
    });
    t1.join();
    t2.join();

    auto& logData = TestLogger::GetLastLogData();

    EXPECT_EQ(logData.lastLevel, "");
    EXPECT_EQ(logData.lastMessage, "");
}