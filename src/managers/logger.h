#ifndef LOGGER_H_
#define LOGGER_H_
#include <fstream>
#include <iostream>
#include <string>

// Simple logger for abstracting file input
class Logger {
public:
	// Disallow any copying of objects of this class
	Logger(const Logger&) = delete;
	Logger& operator=(const Logger&) = delete;

	static Logger& get_instance(const std::string& filepath = "") {
		static Logger instance{filepath};
		return instance;
	}

	void log(const std::string& text) {
		if (!stream.is_open()) {
			std::cout << "Error: Log file is inaccessible!" << std::endl;
			return;
		}
		stream << text;
	}

	void clear() {
		stream.clear();
	}
private:
	// Disallow manual construction of the objects (only through get_instance())
	Logger(const std::string& filepath) : stream{filepath} {}
	~Logger() { stream.close(); }
	std::ofstream stream{};
};

#endif // LOGGER_H_
