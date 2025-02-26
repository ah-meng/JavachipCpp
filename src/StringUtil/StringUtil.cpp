//
// Created by ah-meng on 24. 11. 6.
//

#include <chrono>
#include <sstream>
#include <iomanip>

#include "StringUtil/StringUtil.h"

std::string StringUtil::GetCurrentTimeString(const std::string& format) {
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

std::string StringUtil::GetFileTimeToString(const std::filesystem::file_time_type& time, const std::string& format) {
    // file_time_type을 system_clock::time_point로 변환
    auto sctp = std::chrono::time_point_cast<std::chrono::system_clock::duration>(
        time - std::filesystem::file_time_type::clock::now() +
        std::chrono::system_clock::now());

    // system_clock::time_point를 std::time_t로 변환
    const std::time_t t = std::chrono::system_clock::to_time_t(sctp);

    // std::time_t를 포맷된 문자열로 변환
    const std::tm tm = *std::localtime(&t); // 로컬 시간대 기준으로 변환

    // 포맷팅된 날짜와 시간 문자열 생성
    std::ostringstream oss;
    oss << std::put_time(&tm, format.c_str());

    return oss.str();
}

std::string StringUtil::DecimalToHexString(const int decimal) {
    std::stringstream ss;
    ss << std::hex << decimal;
    return ss.str();
}
