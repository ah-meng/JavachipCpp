//
// Created by JavaChip on 24. 11. 6.
//

#ifndef STRINGUTIL_H
#define STRINGUTIL_H

#include <string>
#include <filesystem>

class StringUtil {
public:
    [[nodiscard]] static std::string GetCurrentTimeString(const std::string& format);

    [[nodiscard]] static std::string GetFileTimeToString(
        const std::filesystem::file_time_type& time,
        const std::string& format = "%Y-%m-%d %H:%M:%S"
    );

    [[nodiscard]] static std::string DecimalToHexString(int decimal);

    /**
     * @brief Byte값을 KB, MB, GB, TB 등의 형식으로 변환
     * @param size 변환할 Byte 크기
     * @param precision 소수점 자릿수 (기본값은 1)
     * @return 변환된 문자열
     * @throws std::invalid_argument 음수를 전달한 경우
     */
    template <typename T>
    [[nodiscard]] static std::string FormatByteSize(T size, const int precision = 1) {
        static_assert(std::is_integral_v<T>, "Only integral types are allowed.");  // 정수만 허용
        if (size < 0)
            throw std::invalid_argument("Negative size values are not allowed.");

        if (precision < 0)
            throw std::invalid_argument("Precision cannot be negative.");  //

        const char* units[] = {"byte", "KB", "MB", "GB", "TB"};
        constexpr size_t unitCount = std::size(units);
        auto displaySize = static_cast<double>(size);
        size_t unitIndex = 0;

        while (displaySize >= 1024.0 && unitIndex < unitCount - 1) {
            displaySize /= 1024.0;
            ++unitIndex;
        }

        std::ostringstream oss;
        oss << std::fixed << std::setprecision(precision) << displaySize << " " << units[unitIndex];
        return oss.str();
    }
};
#endif //STRINGUTIL_H
