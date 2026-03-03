#ifndef INPUT_MANAGER_H_
#define INPUT_MANAGER_H_
#include <iostream>

// Singleton for getting input
class InputManager {
public:
	// Disallow any copying of the class
	InputManager(const InputManager&) = delete;
	InputManager& operator=(const InputManager&) = delete;

	static InputManager& get_instance() {
		static InputManager instance{};
		return instance;
	}

	int get_int(int min, int max) {
		while (true) {
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

	std::string get_string(bool can_be_empty) {
		while (true) {
			std::string str;
			std::cin >> str;

			if (!can_be_empty && str.empty()) {
				std::cout << "String cannot be empty!" << std::endl;
				continue;
			}

			return str;
		}
	}
private:
	// Disallow manual construction of the objects (only through get_instance())
	InputManager() {}
	~InputManager() {}
};

#endif // InputManager
