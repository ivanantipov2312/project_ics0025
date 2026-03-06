#ifndef MENU_H_
#define MENU_H_
#include "../managers/input_manager.h"
#include <string>
#include <vector>
#include <iostream>

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

	int get_option() const {
		return InputManager::get_instance().get_int("Your option: ", 1, options.size());
	}
private:
	std::string name;
	std::vector<std::string> options;
};

class MainMenu : public Menu {
public:
	MainMenu() : Menu({"Main Menu", {
		"Place an order",
		"See current orders from you",
		"List all photographers",
		"Save your current list of orders",
		"Quit"
	}}) {}
};

class OrderMenu : public Menu {
public:
	OrderMenu() : Menu({"Order placement", {
		"Place an order",
		"Quit"
	}}) {}
};

#endif // MENU_H_
