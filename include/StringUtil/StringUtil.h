//
// Created by JavaChip on 24. 11. 6.
//

#ifndef STRINGUTIL_H
#define STRINGUTIL_H

#include <string>

class StringUtil {
public:
    [[nodiscard]] static std::string GetCurrentTimeString(const std::string& format);
};
#endif //STRINGUTIL_H
