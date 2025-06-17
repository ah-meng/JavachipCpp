include(FetchContent)

# FetchContent로 asio 가져오기
FetchContent_Declare(
        asio
        GIT_REPOSITORY https://github.com/chriskohlhoff/asio.git
        GIT_TAG        asio-1-34-2 # 사용하려는 버전 태그 (필요에 따라 최신 버전으로 변경 가능)
)

FetchContent_MakeAvailable(asio)
set(ASIO_INCLUDE_DIR ${asio_SOURCE_DIR}/asio/include)
# asio 추가
target_include_directories(${PROJECT_NAME} PRIVATE ${ASIO_INCLUDE_DIR})
