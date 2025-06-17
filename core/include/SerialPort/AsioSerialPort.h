//
// Created by bklee on 25. 6. 17.
//

#ifndef ASIOSERIALPORT_H
#define ASIOSERIALPORT_H

#include <SerialPort/ISerialPort.h>
#include <asio.hpp>

class AsioSerialPort : public ISerialPort {
public:
    bool open(const std::string &portName, const Settings &settings) override;

    void close() override;

    bool isOpen() const override;

    std::size_t write(const std::vector<uint8_t> &data) override;

    std::vector<uint8_t> read(std::size_t bytes) override;

    void asyncWrite(const std::vector<uint8_t> &data, std::function<void(std::size_t)> callback) override;

    void asyncRead(std::size_t bytes, std::function<void(std::vector<uint8_t>)> callback) override;

    void setBaudRate(unsigned baudRate) override;

    void setFlowControl(Settings::FlowControl flowControl) override;

    void setTimeout(unsigned milliseconds) override;

    bool isCTS() const override;

    bool isDSR() const override;

    void setDTR(bool value) override;

    void setRTS(bool value) override;
};


#endif //ASIOSERIALPORT_H
