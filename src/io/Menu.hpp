#ifndef MENU_HPP_
#define MENU_HPP_
#include "../io/InputManager.hpp"
#include <string>
#include <vector>
#include <iostream>

// TODO: Refactor this into builder pattern if makes sense
// Simple class for quick creation of menus
class Menu {
public:
	Menu(const std::string& name, const std::vector<std::string>& options)
		: name{name}, options{options} {}

	void render() const {
		std::cout << name << ": " << std::endl;
		for (int i = 0; i < options.size(); i++) {
			std::cout << (i + 1) << ". " << options[i] << std::endl;
		}
	}

	int get_option(InputManager& input) const {
		return input.get_int("Your option: ", 1, options.size());
	}
private:
	std::string name;
	std::vector<std::string> options;
};

#endif // MENU_HPP_
