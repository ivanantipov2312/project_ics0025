#ifndef MENU_H_
#define MENU_H_
#include <string>
#include <vector>
#include <iostream>

class Menu {
public:
	Menu(const std::string& name, const std::vector<std::string>& options)
		: name{name}, options{options} {}
	void render() {
		std::cout << name << ": " << std::endl;
		for (int i = 0; i < options.size(); i++) {
			std::cout << (i + 1) << ". " << options[i] << std::endl;
		}
	}

	int get_option() {
		while (true) {
			std::cout << "Your option: ";
			int i;
			std::cin >> i;
			if (i < 0 || i > options.size()) {
				std::cout << "Invalid option" << std::endl;
				continue;
			}
			return i;
		}
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
		"Quit"
	}}) {}
};

#endif // MENU_H_
