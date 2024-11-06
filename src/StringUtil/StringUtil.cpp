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
