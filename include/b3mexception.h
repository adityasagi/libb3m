#pragma once

#include <sstream>
#include <string>
#include <exception>

namespace kondo {
  class B3MException : public std::exception {
  public:
    std::string message;
    uint8_t errorCode;
  public:
    B3MException(uint8_t errorCode) { this->errorCode = errorCode;}
    virtual ~B3MException() throw() {}

  public:
    const char *what() const throw() {
      if (errorCode == 0) {
	return message.c_str();
      }
      std::ostringstream ss;
      ss << message << "(errorCode=" << errorCode << ")";
      return ss.str().c_str();
    }
  };

  class TimeoutException : public B3MException {
  public:
  TimeoutException() : B3MException(0) {
      message = "TimeoutException";
    }
  };

  class ChecksumException : public B3MException {
  public:
  ChecksumException() : B3MException(0) {
      message = "ChecksumException";
    }
  };

  class ErrorStatusException : public B3MException {
  public:
  ErrorStatusException(status_t status = 0) : B3MException(status) {
      message = "ErrorStatusException";
    }
  };

  class SystemException : public B3MException {
  public:
  SystemException(status_t status = 0) : B3MException(status) {
      message = "SystemException";
    }
  };

  class MotorException : public B3MException {
  public:
  MotorException(status_t status = 0) : B3MException(status) {
      message = "MotorException";
    }
  };

  class UARTException : public B3MException {
  public:
  UARTException(status_t status = 0) : B3MException(status) {
      message = "UARTException";
    }
  };

  class CommandException : public B3MException {
  public:
  CommandException(status_t status = 0) : B3MException(status) {
      message = "CommandException";
    }
  };

};

