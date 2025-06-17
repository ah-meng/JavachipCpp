//
// Created by bklee on 25. 6. 17.
//

#include "SerialPort/AsioSerialPort.h"

bool AsioSerialPort::open(const std::string &portName, const Settings &settings) {

}

void AsioSerialPort::close() {
}

bool AsioSerialPort::isOpen() const {
}

std::size_t AsioSerialPort::write(const std::vector<uint8_t> &data) {
}

std::vector<uint8_t> AsioSerialPort::read(std::size_t bytes) {
}

void AsioSerialPort::asyncWrite(const std::vector<uint8_t> &data, std::function<void(std::size_t)> callback) {
}

void AsioSerialPort::asyncRead(std::size_t bytes, std::function<void(std::vector<uint8_t>)> callback) {
}

void AsioSerialPort::setBaudRate(unsigned baudRate) {
}

void AsioSerialPort::setFlowControl(Settings::FlowControl flowControl) {
}

void AsioSerialPort::setTimeout(unsigned milliseconds) {
}

bool AsioSerialPort::isCTS() const {
}

bool AsioSerialPort::isDSR() const {
}

void AsioSerialPort::setDTR(bool value) {
}

void AsioSerialPort::setRTS(bool value) {
}
