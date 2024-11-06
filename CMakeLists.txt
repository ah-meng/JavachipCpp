cmake_minimum_required(VERSION 3.5)

project(
        JavaChipCpp
        VERSION 0.1
        DESCRIPTION "Core Lib For Cpp"
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)


set(SOURCES
        src/DynamicLoader/DynamicLoader.cpp
        src/DynamicLoader/DynamicLoaderPlatform.cpp
        src/Logger/LoggerBase.cpp
        src/Logger/ConsoleLogger.cpp
        src/Logger/FileLogger.cpp
        src/StringUtil/StringUtil.cpp
)
add_subdirectory(test)

add_library(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)