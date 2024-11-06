# GetCurrentTimeString

`GetCurrentTimeString` 함수는 현재 시간을 지정된 형식의 문자열로 반환합니다.

```c++
std::string StringUtil::GetCurrentTimeString(const std::string& format);
```


### 매개변수

- **format**: `const std::string&`
    - 시간 형식을 나타내는 문자열입니다. [`std::put_time`](https://en.cppreference.com/w/cpp/io/manip/put_time)에서 사용되는 형식 지정자를 사용할 수 있습니다.
    - 예를 들면, `"%\Y-%m-%d %H:%M:%S"`는 "년-월-일 시:분:초" 형식의 문자열을 반환합니다.

### 반환 값

- **std::string**: 형식이 지정된 현재 시간 문자열을 반환합니다.

### 예제

다음은 `GetCurrentTimeString` 함수를 사용하는 예제입니다.

```c++
#include "StringUtil.h"
#include <iostream>

int main() {
    std::string currentTime = StringUtil::GetCurrentTimeString("%\Y-%m-%d %H:%M:%S");
    std::cout << "현재 시간: " << currentTime << std::endl;
    return 0;
}
```
