cmake_minimum_required(VERSION 3.20)
project(JavaChipCpp_Core LANGUAGES CXX)

# 구현체 라이브러리 (STATIC 혹은 SHARED로 변경 가능)
add_library(${PROJECT_NAME} STATIC
        src/DynamicLoader/DynamicLoader.cpp
        src/DynamicLoader/DynamicLoaderPlatform.cpp
        src/Logger/LoggerBase.cpp
        src/Logger/ConsoleLogger.cpp
        src/Logger/FileLogger.cpp
        src/StringUtil/StringUtil.cpp
)
add_library(JavaChipCpp::Core ALIAS ${PROJECT_NAME})

# C++17 요구사항 (API에도 전파)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

# 인클루드 디렉토리 설정
target_include_directories(${PROJECT_NAME}
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# API 모듈 의존 (PUBLIC으로 전파)
target_link_libraries(${PROJECT_NAME}
        PUBLIC JavaChipCpp::Api
)

add_subdirectory(test)

# export 그룹에 포함시키기
install(TARGETS ${PROJECT_NAME}
        EXPORT JavaChipCppTargets
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include
)