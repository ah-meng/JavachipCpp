# ILogger

<secondary-label ref="interface"/>

## Summary

`ILogger`는 다양한 로깅 레벨을 제공하는 인터페이스입니다. 이 인터페이스는 모든 로거 클래스가 구현해야 할 일관된 메서드를 정의하여, 로그 메시지를 기록하는 통합된 방법을 제공합니다.

---

## Syntax

``` c++
class ILogger {
public:
    virtual void Info(const std::string& message) = 0;
    virtual void Debug(const std::string& message) = 0;
    virtual void Warn(const std::string& message) = 0;
    virtual void Error(const std::string& message) = 0;
    virtual void Fatal(const std::string& message) = 0;
    virtual ~ILogger() = default;
};
```

---

## Members

### Public Member Functions

- **`void Info(const std::string& message)`**
    - **Description**: 일반적인 정보 메시지를 기록합니다.
    - **Usage**: `logger->Info("Starting application.");`

- **`void Debug(const std::string& message)`**
    - **Description**: 디버깅 정보를 기록합니다.
    - **Usage**: `logger->Debug("Processing user input.");`

- **`void Warn(const std::string& message)`**
    - **Description**: 경고 메시지를 기록합니다.
    - **Usage**: `logger->Warn("Potential issue detected.");`

- **`void Error(const std::string& message)`**
    - **Description**: 오류 메시지를 기록합니다.
    - **Usage**: `logger->Error("File not accessible.");`

- **`void Fatal(const std::string& message)`**
    - **Description**: 치명적인 오류 메시지를 기록합니다.
    - **Usage**: `logger->Fatal("Critical system failure.");`

- **`~ILogger()`**
    - **Description**: 가상 소멸자. `ILogger`가 기본 인터페이스 역할을 할 수 있도록 합니다.

---

## Remarks

`ILogger` 인터페이스는 각 로거 클래스가 일관된 API를 통해 메시지를 기록할 수 있도록 설계되었습니다. 이를 상속하는 클래스는 각 메서드를 특정 출력 방식에 맞게 구현해야 합니다. 예를 들어,
`ConsoleLogger`는 메시지를 콘솔에 출력하고, `FileLogger`는 파일에 기록합니다.

---

## Examples

아래는 `ILogger`를 상속하여 콘솔에 메시지를 출력하는 `ConsoleLogger` 클래스의 예시입니다.

``` c++
class ConsoleLogger : public ILogger {
public:
void Info(const std::string& message) override {
std::cout << "[INFO] " << message << std::endl;
}
void Debug(const std::string& message) override {
std::cout << "[DEBUG] " << message << std::endl;
}
// 나머지 메서드도 유사하게 구현...
};
```

---

## See Also

- **[](BaseLogger.md)**: 기본 로거 클래스. `ILogger`를 상속하고, 공통 로깅 기능을 제공합니다.
- **[](ConsoleLogger.md)**: 콘솔에 로그를 기록하는 구현.
- **[BasicFileLogger](FileLogger.md)**: 파일에 로그를 기록하는 구현.
