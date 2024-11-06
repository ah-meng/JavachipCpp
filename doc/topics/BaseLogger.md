# LoggerBase

<secondary-label ref="abstract"/>

## Summary

`LoggerBase`는 `ILogger` 인터페이스를 구현하고, 기본적인 로깅 기능을 제공하는 추상 클래스입니다. 이 클래스는 스레드 안전한 로깅을 지원하며, 로그 메시지의 타임스탬프를 포함하는 기능을 제공합니다.
구체적인 로그 출력 방식은 이를 상속받는 클래스에서 정의합니다.

---

## Syntax

```c++
class LoggerBase : public ILogger {
public:
    void Info(const std::string& message) override;
    void Debug(const std::string& message) override;
    void Warn(const std::string& message) override;
    void Error(const std::string& message) override;
    void Fatal(const std::string& message) override;

protected:
    virtual void Log(const std::string& level, const std::string& message) = 0;
    [[nodiscard]] static std::string GetCurrentTimeString(const std::string& format);

private:
    virtual void LogWithMutex(const std::string& level, const std::string& message);
    std::mutex mutex;
};
```

---

## Members

### Public Member Functions

- **`void Info(const std::string& message)`**
    - **Description**: `INFO` 레벨의 메시지를 기록합니다. `LogWithMutex`를 호출하여 스레드 안전하게 로그를 기록합니다.
    - **Usage**: `loggerBaseInstance->Info("Application started");`

- **`void Debug(const std::string& message)`**
    - **Description**: `DEBUG` 레벨의 메시지를 기록합니다.
    - **Usage**: `loggerBaseInstance->Debug("Debugging user input");`

- **`void Warn(const std::string& message)`**
    - **Description**: `WARN` 레벨의 메시지를 기록합니다.
    - **Usage**: `loggerBaseInstance->Warn("Deprecated function used");`

- **`void Error(const std::string& message)`**
    - **Description**: `ERROR` 레벨의 메시지를 기록합니다.
    - **Usage**: `loggerBaseInstance->Error("File not found");`

- **`void Fatal(const std::string& message)`**
    - **Description**: `FATAL` 레벨의 메시지를 기록합니다.
    - **Usage**: `loggerBaseInstance->Fatal("System failure");`

### Protected Member Functions

- **`void Log(const std::string& level, const std::string& message) = 0`**
    - **Description**: 순수 가상 함수로, 로그 메시지의 구체적인 출력 방식을 정의하기 위해 파생 클래스에서 구현해야 합니다.

- **`static std::string GetCurrentTimeString(const std::string& format)`**
    - **Description**: 주어진 형식에 따라 현재 시간을 문자열로 반환합니다. 로그 메시지에 타임스탬프를 추가하는 데 사용됩니다.
    - **Usage**: `std::string currentTime = GetCurrentTimeString("%Y-%m-%d %H:%M:%S");`

### Private Member Functions

- **`void LogWithMutex(const std::string& level, const std::string& message)`**
    - **Description**: `mutex`를 사용하여 스레드 안전하게 로그 메시지를 기록합니다. `Log` 메서드를 호출하여 구체적인 로그 출력을 수행합니다.
    - **Usage**: 이 메서드는 `LoggerBase`의 메서드 내에서만 호출됩니다.

---

## Remarks

`LoggerBase`는 로그를 기록할 때 스레드 안전성을 보장하기 위해 `std::mutex`를 사용하여 메시지를 출력합니다. 구체적인 로깅 출력 형식은 `Log` 메서드를 상속받은 클래스에서 구현해야 합니다.
`GetCurrentTimeString` 메서드는 로그 메시지에 타임스탬프를 추가하는 데 유용하게 사용할 수 있습니다.

---

## Examples

아래는 `LoggerBase`를 상속하여 콘솔에 로그를 출력하는 `ConsoleLogger` 클래스의 예시입니다.

```c++
class ConsoleLogger : public LoggerBase {
protected:
void Log(const std::string& level, const std::string& message) override {
std::cout << "[" << GetCurrentTimeString("%H:%M:%S") << "] [" << level << "] " << message << std::endl;
}
};
```

---

## See Also

- **[](ILogger.md)**: `LoggerBase`가 구현하는 인터페이스로, 기본적인 로깅 메서드를 정의합니다.
- **ConsoleLogger**: 콘솔에 로그를 출력하는 클래스.
- **BasicFileLogger**: 파일에 로그를 출력하는 클래스.
