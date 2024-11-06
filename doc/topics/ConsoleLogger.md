# ConsoleLogger

## Inheritance Hierarchy
```
ILogger
└── LoggerBase
    └── ConsoleLogger
```

## Summary

`ConsoleLogger`는 `LoggerBase`를 상속받아 콘솔에 로그 메시지를 출력하는 클래스입니다. 이 클래스는 `Log` 메서드를 구현하여 메시지를 표준 출력(`std::cout`)에 출력하며, 로그
레벨과 타임스탬프가 포함된 메시지를 형식화하여 제공합니다.

---

## Syntax

```cpp
class ConsoleLogger final : public LoggerBase {
protected:
void Log(const std::string& level, const std::string& message) override;
};
```

---

## Members

### Protected Member Functions

- **`void Log(const std::string& level, const std::string& message)`**
    - **Description**: `LoggerBase`의 추상 메서드를 구현하여 로그 메시지를 콘솔에 출력합니다. 출력되는 메시지에는 타임스탬프와 로그 레벨이 포함됩니다.
    - **Usage**: 파생 클래스인 `LoggerBase`의 메서드를 통해 호출됩니다.
    - **Example Output**: `[12:34:56] [INFO] Application started`

---

## Remarks

`ConsoleLogger`는 콘솔을 기본 출력으로 사용하며, `Log` 메서드를 통해 형식화된 로그 메시지를 출력합니다. 이 클래스는 로그 메시지의 타임스탬프 형식을 `%H:%M:%S`로 고정하여, 시간 정보를
포함한 형태로 메시지를 표시합니다.

스레드 안전성은 `LoggerBase`에서 제공하는 `LogWithMutex` 메서드를 통해 보장되므로, 여러 스레드에서 동시에 `ConsoleLogger`를 사용할 때도 안전합니다.

---

## Examples

아래는 `ConsoleLogger`를 사용하여 `INFO` 메시지를 기록하는 예시입니다.

```cpp
ConsoleLogger logger;
logger.Info("Application started");
// 출력 예시: [12:34:56] [INFO] Application started
```

---

## See Also

- **LoggerBase**: `ConsoleLogger`가 상속받는 기본 클래스. 기본적인 로깅 및 스레드 안전성을 제공합니다.
- **ILogger**: 모든 로거가 구현해야 할 로깅 인터페이스입니다.
