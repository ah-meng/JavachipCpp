cmake_minimum_required(VERSION 3.20)

project(
        JavaChipCpp
        VERSION 0.0.1
        DESCRIPTION "Core Lib For Cpp"
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

add_subdirectory(api)
add_subdirectory(core)

# -- Packaging 스캐폴딩 --
include(CMakePackageConfigHelpers)

# 버전 파일 생성
write_basic_package_version_file(
        "${CMAKE_CURRENT_BINARY_DIR}/JavaChipCppConfigVersion.cmake"
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY AnyNewerVersion
)

# Config 파일 생성 (cmake/JavaChipCppConfig.cmake.in 필요)
configure_package_config_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake/JavaChipCppConfig.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/JavaChipCppConfig.cmake"
        INSTALL_DESTINATION lib/cmake/JavaChipCpp
)

# Targets export
install(EXPORT JavaChipCppTargets
        NAMESPACE JavaChipCpp::
        DESTINATION lib/cmake/JavaChipCpp
)