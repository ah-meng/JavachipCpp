# BasicFileLogger

## Inheritance Hierarchy

```
ILogger
└── LoggerBase
    └── BasicFileLogger
```

## Summary

`BasicFileLogger`는 `LoggerBase`를 상속받아 파일에 로그 메시지를 기록하는 클래스입니다. 로그 파일은 날짜별로 자동으로 관리되며, 매일 새로운 로그 파일이 생성됩니다.
`BasicFileLogger`는 지정된 디렉터리에 로그 파일을 저장하며, 파일 입출력을 처리하기 위해 `std::ofstream`을 사용합니다.

---

## Syntax

```c++
class BasicFileLogger final : public LoggerBase {
public:
    explicit BasicFileLogger(const std::string& logDirectory);

protected:
    void Log(const std::string& level, const std::string& message) override;

private:
    std::string logDirectory;
    std::ofstream logFile;
    std::string currentDate;

    bool IsDateChanged() const;
    void UpdateLogFile();
    static std::string GenerateFileName();
    static std::string GenerateDateString();
};
```

---

## Members

### Public Member Functions

- **`explicit BasicFileLogger(const std::string& logDirectory)`**
    - **Description**: 로그 파일을 저장할 디렉터리를 지정하여 `BasicFileLogger`를 초기화합니다. 지정된 디렉터리가 존재하지 않으면 생성합니다.
    - **Parameters**:
        - `logDirectory`: 로그 파일을 저장할 디렉터리 경로.
    - **Usage**: `BasicFileLogger fileLogger("/var/logs");`

### Protected Member Functions

- **`void Log(const std::string& level, const std::string& message)`**
    - **Description**: `LoggerBase`의 추상 메서드를 구현하여 로그 메시지를 파일에 기록합니다. 날짜가 변경되면 새로운 로그 파일을 생성합니다.

### Private Member Functions

- **`bool IsDateChanged() const`**
    - **Description**: 현재 날짜가 변경되었는지 확인합니다. 로그 파일이 날짜별로 구분되므로, 날짜 변경 시 새 파일로 전환됩니다.

- **`void UpdateLogFile()`**
    - **Description**: 날짜가 변경된 경우, 기존 파일을 닫고 새로운 파일을 생성합니다.

- **`static std::string GenerateFileName()`**
    - **Description**: 날짜를 기반으로 한 로그 파일 이름을 생성합니다.

- **`static std::string GenerateDateString()`**
    - **Description**: 현재 날짜를 문자열 형식으로 반환합니다.

---

## Remarks

`BasicFileLogger`는 로그를 파일에 기록할 때, 날짜가 변경되면 자동으로 새 파일을 생성하는 기능을 갖추고 있습니다. `logDirectory`에 지정된 위치에 로그 파일이 저장되며, 파일 이름은
`log_YYYY-MM-DD` 형식으로 날짜를 포함합니다. 이를 통해 각 로그 파일이 날짜별로 관리됩니다.

---

## Examples

아래는 `BasicFileLogger`를 사용하여 로그 메시지를 기록하는 예시입니다.

```c++
BasicFileLogger logger("/var/logs");
logger.Info("Application started");
logger.Error("File not accessible");
// 출력 예시: /var/logs/log_2024-11-06 파일에 [12:34:56] [INFO] Application started 기록
```

---

## See Also

- **[](ILogger.md)**: 모든 로거가 구현해야 할 로깅 인터페이스입니다.
- **[](BaseLogger.md)**: `BasicFileLogger`가 상속받는 기본 클래스. 기본적인 로깅 및 스레드 안전성을 제공합니다.
