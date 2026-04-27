#ifndef INPUT_MANAGER_HPP_
#define INPUT_MANAGER_HPP_
#include <iostream>
#include <limits>

// Helper for getting input with prompts
class InputManager {
public:
	int get_int(const std::string& prompt, int min, int max) {
		int n;
		while (true) {
			std::cout << prompt;
			std::cin >> n;

			// If input extraction is failed
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Failed to get input!" << std::endl;
				continue;
			}

			// Remove trailing '\n' (in case anything is left)
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		
			// if less than min or bigger than max
			if (n < min || n > max) {
				std::cout << "Invalid option!" << std::endl;
				continue;
			}
			
			break;
		}

		return n;
	}

	std::string get_string(const std::string& prompt, bool can_be_empty = false) {
		while (true) {
			std::cout << prompt;
			std::string str;
			std::getline(std::cin, str);

			if (!can_be_empty && str.empty()) {
				std::cout << "String cannot be empty!" << std::endl;
				continue;
			}

			return str;
		}
	}

	// Useful for "Continue (y/n)" questions
	bool get_yes_or_no(const std::string& prompt) {
		while (true) {
			std::cout << prompt;
			char c;
			std::cin >> c;

			char ret = tolower(c);

			if (ret != 'y' && ret != 'n') {
				continue;
			}

			return c == 'y';
		}
	}
};

#endif // INPUT_MANAGER_HPP_
