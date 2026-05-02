#ifndef LOGGER_HPP_
#define LOGGER_HPP_
#include <fstream>
#include <iostream>
#include <string>
#include <mutex>

enum class LogLevel {
	Info,
	Warn,
	Error,
};

// Simple logger for abstracting system messages
class Logger {
public:
	Logger(const std::string& filepath) : stream{filepath} {}
	~Logger() { stream.close(); }
	
	void log(LogLevel level, const std::string& text) {
		std::lock_guard<std::mutex> lock{mtx};

		if (!stream.is_open()) {
			std::cout << "Error: Log file is inaccessible!" << std::endl;
			return;
		}

		switch (level) {
		case LogLevel::Error:
			stream << "[ERROR] ";
			break;
		case LogLevel::Info:
			stream << "[INFO] ";
			break;
		case LogLevel::Warn:
			stream << "[WARN] ";
			break;
		default:
			break;
		};

		stream << text << std::endl;
	}

	void clear() {
		stream.clear();
	}
private:
	std::ofstream stream{};
	std::mutex mtx{};
};

#endif // LOGGER_HPP_
