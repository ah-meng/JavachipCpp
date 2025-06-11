#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <DynamicLoader/DynamicLoader.h>
#include <DynamicLoader/IDynamicLoaderPlatform.h>

using ::testing::Return;
using ::testing::Throw;
using ::testing::StrictMock;

class MockDynamicLoaderPlatform : public IDynamicLoaderPlatform {
public:
    MOCK_METHOD(void*, LoadDynamicLibrary, (const std::string& path), (override));
    MOCK_METHOD(void*, GetFunction, (void* handle, const std::string& name), (override));
    MOCK_METHOD(void, UnloadLibrary, (void* handle), (override));
};

TEST(DynamicLoaderTest, LoadLibrarySuccess) {
    auto mockPlatform = std::make_unique<StrictMock<MockDynamicLoaderPlatform>>();
    void* mockHandle = reinterpret_cast<void*>(0x1);

    EXPECT_CALL(*mockPlatform, LoadDynamicLibrary("test.dll"))
        .WillOnce(Return(mockHandle));
    EXPECT_CALL(*mockPlatform, UnloadLibrary(mockHandle));

    DynamicLoader loader("test.dll", std::move(mockPlatform));
}

TEST(DynamicLoaderTest, LoadLibraryFailure) {
    auto mockPlatform = std::make_unique<StrictMock<MockDynamicLoaderPlatform>>();

    EXPECT_CALL(*mockPlatform, LoadDynamicLibrary("missing.dll"))
        .WillOnce(Throw(std::runtime_error("Failed to load library")));

    EXPECT_THROW(DynamicLoader loader("missing.dll", std::move(mockPlatform)), std::runtime_error);
}

TEST(DynamicLoaderTest, LoadFunctionSuccess) {
    auto mockPlatform = std::make_unique<StrictMock<MockDynamicLoaderPlatform>>();
    void* mockHandle = reinterpret_cast<void*>(0x1);
    void (*mockFunc)() = reinterpret_cast<void(*)()>(0x2);

    EXPECT_CALL(*mockPlatform, LoadDynamicLibrary("test.dll"))
        .WillOnce(Return(mockHandle));
    EXPECT_CALL(*mockPlatform, GetFunction(mockHandle, "testFunction"))
        .WillOnce(Return(reinterpret_cast<void*>(mockFunc)));
    EXPECT_CALL(*mockPlatform, UnloadLibrary(mockHandle));

    DynamicLoader loader("test.dll", std::move(mockPlatform));
    auto func = loader.LoadFunction<void(*)()>("testFunction");

    EXPECT_EQ(func, mockFunc);
}

TEST(DynamicLoaderTest, LoadFunctionFailure) {
    auto mockPlatform = std::make_unique<StrictMock<MockDynamicLoaderPlatform>>();
    void* mockHandle = reinterpret_cast<void*>(0x1);

    EXPECT_CALL(*mockPlatform, LoadDynamicLibrary("test.dll"))
        .WillOnce(Return(mockHandle));
    EXPECT_CALL(*mockPlatform, GetFunction(mockHandle, "missingFunction"))
        .WillOnce(Return(nullptr));
    EXPECT_CALL(*mockPlatform, UnloadLibrary(mockHandle));

    DynamicLoader loader("test.dll", std::move(mockPlatform));
    EXPECT_THROW(loader.LoadFunction<void(*)()>("missingFunction"), std::runtime_error);
}

TEST(DynamicLoaderTest, UnloadLibrary) {
    auto mockPlatform = std::make_unique<StrictMock<MockDynamicLoaderPlatform>>();
    void* mockHandle = reinterpret_cast<void*>(0x1);

    EXPECT_CALL(*mockPlatform, LoadDynamicLibrary("test.dll"))
        .WillOnce(Return(mockHandle));
    EXPECT_CALL(*mockPlatform, UnloadLibrary(mockHandle));

    {
        DynamicLoader loader("test.dll", std::move(mockPlatform));
    } // 소멸자 호출 시 UnloadLibrary가 호출되는지 확인
}
