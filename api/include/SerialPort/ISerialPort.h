//
// Created by 이채호 on 25. 6. 12.
//

#ifndef ISERIALPORT_H
#define ISERIALPORT_H

#include <string>
#include <vector>
#include <functional>

class ISerialPort
{
public:
    struct Settings
    {
        unsigned int baudRate = 9600;
        unsigned int dataBits = 8;
        unsigned int stopBits = 1;
        bool parityEnable = false;

        enum class Parity
        {
            None,
            Odd,
            Even
        } parityType = Parity::None;

        enum class FlowControl
        {
            None,
            Software,
            Hardware
        } flowControl = FlowControl::None;
    };

    virtual ~ISerialPort() = default;

    // 포트 제어
    virtual bool open(const std::string& portName, const Settings& settings = Settings{}) = 0;
    virtual void close() = 0;
    virtual bool isOpen() const = 0;

    // 동기식 작업
    virtual std::size_t write(const std::vector<uint8_t>& data) = 0;
    virtual std::vector<uint8_t> read(std::size_t bytes) = 0;

    // 비동기식 작업
    virtual void asyncWrite(const std::vector<uint8_t>& data,
                            std::function<void(std::size_t)> callback) = 0;
    virtual void asyncRead(std::size_t bytes,
                           std::function<void(std::vector<uint8_t>)> callback) = 0;

    // 포트 설정
    virtual void setBaudRate(unsigned int baudRate) = 0;
    virtual void setFlowControl(Settings::FlowControl flowControl) = 0;
    virtual void setTimeout(unsigned int milliseconds) = 0;

    // 포트 상태
    virtual bool isCTS() const = 0;
    virtual bool isDSR() const = 0;
    virtual void setDTR(bool value) = 0;
    virtual void setRTS(bool value) = 0;
};

#endif //ISERIALPORT_H
