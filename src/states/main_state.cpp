#include "main_state.h"

void MainState::handle_events(StateManager& manager) const {
	int opt = menu.get_option();
	if (opt == 1) { // Order
		manager.change(std::make_unique<OrderState>(OrderState{}));
	} else if (opt == 2) { // List orders
		auto q = OrderManager::get_instance().get_queue();
		std::cout << "Your orders: " << std::endl;
		for (const auto& el : q) {
			el.print();
		}
	} else if (opt == 3) { // List photographers
		auto photographers = UserManager::get_instance().get_users_by_role(Role::Photographer);
		for (const auto& el : photographers) {
			std::cout << el.username << " | " << el.email << std::endl;
		}
	}
	else if (opt == 4) { // Save current ordering list
		std::string filepath = InputManager::get_instance().get_string("Enter filepath: ");
		auto q = OrderManager::get_instance().get_queue();
		for (const auto& el : q) {
			Logger::get_instance(filepath).log(el.to_string());
		}
	} else if (opt == 5) { // Logout
		manager.change(std::make_unique<LoginState>(LoginState{}));
	} else if (opt == 6) { // Quit
		manager.stop();
	}
}
