cmake_minimum_required(VERSION 3.14)
project(JavaChipCpp_test)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.15.0.zip
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} include)

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/DynamicLoader/DynamicLoaderTest.cpp
        src/DynamicLoader/DynamicLoaderRealDllTest.cpp
        src/Logger/LoggerTest.cpp
        src/Logger/BasicLoggerTest.cpp
        src/Serializable/SerializableTest.cpp
        src/StringUtil/StringUtilTest.cpp
)

target_link_libraries(${PROJECT_NAME} gtest_main gmock_main JavaChipCpp::Core)
include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})