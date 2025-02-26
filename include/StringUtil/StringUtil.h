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
};
#endif //STRINGUTIL_H
