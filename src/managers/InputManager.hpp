#ifndef INPUT_MANAGER_HPP_
#define INPUT_MANAGER_HPP_
#include <iostream>

// Singleton for getting input
class InputManager {
public:
	int get_int(const std::string& prompt, int min, int max) {
		while (true) {
			std::cout << prompt;
			int n;
			std::cin >> n;
		
			// if less than min or bigger than max
			if (n < min || n > max) {
				std::cout << "Invalid option!" << std::endl;
				continue;
			}

			return n;
		}
	}

	std::string get_string(const std::string& prompt, bool can_be_empty = false) {
		while (true) {
			std::cout << prompt;
			std::string str;
			std::cin >> str;

			if (!can_be_empty && str.empty()) {
				std::cout << "String cannot be empty!" << std::endl;
				continue;
			}

			return str;
		}
	}

	// Useful for "Continue (y/n)" questions
	bool get_yes_or_no(const std::string& prompt, char yes_char = 'y', char no_char = 'n') {
		while (true) {
			std::cout << prompt;
			char c;
			std::cin >> c;

			if (c != yes_char && c != no_char) {
				continue;
			}

			return c == yes_char;
		}
	}
private:
	// Disallow manual construction of the objects (only through get_instance())
	InputManager() {}
	~InputManager() {}
};

#endif // INPUT_MANAGER_HPP_
