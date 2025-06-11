cmake_minimum_required(VERSION 3.20)
project(JavaChipCpp_Api LANGUAGES CXX)

# 헤더 전용 인터페이스 라이브러리
add_library(${PROJECT_NAME} INTERFACE)
add_library(JavaChipCpp::Api ALIAS ${PROJECT_NAME})

# C++17 요구사항 전파
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_17)

# 인클루드 디렉토리 설정: 빌드 트리 vs 설치 트리
target_include_directories(${PROJECT_NAME}
        INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# export 그룹에 포함시키기
install(TARGETS ${PROJECT_NAME}
        EXPORT JavaChipCppTargets
        INCLUDES DESTINATION include
)