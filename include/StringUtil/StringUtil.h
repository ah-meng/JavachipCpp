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
     * @brief 주어진 바이트(Byte) 값을 KB, MB, GB, TB 등의 단위로 변환하여 문자열로 반환합니다.
     *
     * @details
     *  입력된 `size` 값을 적절한 단위로 변환합니다.
     *  변환된 값은 `precision`에 따라 소수점 이하 자리수를 지정하여 나타냅니다.
     *
     * @param size 변환할 바이트 크기 (0 이상이어야 함)
     * @param precision 변환된 값의 소수점 이하 자릿수 (0 이상이어야 하며 기본값은 1)
     * @return 단위와 함께 변환된 크기를 나타내는 문자열 (예: "1.0 KB", "1.00 MB")
     * @throws std::invalid_argument `size`가 음수인 경우
     * @throws std::invalid_argument `precision`이 음수인 경우
     *
     * @note 지원되는 단위는 "byte", "KB", "MB", "GB", "TB"로 최대 TB까지 변환 가능합니다.
     *
     * @example
     * - `FormatByteSize(1024)` -> "1.0 KB"
     * - `FormatByteSize(1048576, 2)` -> "1.00 MB"
     * - `FormatByteSize(1073741824, 3)` -> "1.000 GB"
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
