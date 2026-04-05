#include "state.h"
#include "../managers/order_mananger.h"
#include "../managers/logger.h"
#include "../managers/input_manager.h"
#include "../managers/user_manager.h"

std::unique_ptr<State> LoginState::handle_events() const {
	int opt = login_menu.get_option();
		if (opt == 1) { // Login
			std::string username = InputManager::get_instance().get_string("Username: ");
			const User* user = UserManager::get_instance().get_user(username);
			if (user == nullptr) {
				std::cout << "No such user exists! Register!" << std::endl;
				return std::make_unique<LoginState>(*this);
			}

			int attempts = 0;
			while (attempts < 3) {
				std::string password = InputManager::get_instance().get_string("Password: ");
				if (user->password == password) {
					return std::make_unique<MainState>(MainState{}); // If correct, transfer to the main state
				}
				std::cout << "Wrong password! (" << (attempts + 1) << "/3 attempts): " << std::endl;
				attempts++;
			}
		} else if (opt == 2) { // Register
			std::string username = InputManager::get_instance().get_string("Enter your username: ");
			if (UserManager::get_instance().get_user(username) != nullptr) {
				std::cout << "User with this username already exists!" << std::endl;
				return std::make_unique<LoginState>(*this);
			}

			std::string email = InputManager::get_instance().get_string("Enter your email: ");
			std::string password = InputManager::get_instance().get_string("Enter your password: ");
			bool is_photographer = InputManager::get_instance().get_yes_or_no("Are you a photographer? ");
			User user = {username, email, password, is_photographer ? Role::Photographer : Role::Customer};
			UserManager::get_instance().add_user(user);
			return std::make_unique<MainState>(MainState{});
		} else if (opt == 3) { // Exit
			return std::make_unique<ExitState>(ExitState{});
		}
	return std::make_unique<LoginState>(*this);
}

std::unique_ptr<State> MainState::handle_events() const {
	int opt = menu.get_option();
	if (opt == 1) { // Order
		return std::make_unique<OrderState>(OrderState{});
	} else if (opt == 2) { // List orders
		auto q = OrderManager::get_instance().get_queue();
		std::cout << "Your orders: " << std::endl;
		for (const auto& el : q) {
			el.print();
		}
	} else if (opt == 3) { // List photographers
		// TODO: Add photographer logic here
		std::cout << "This functionality is not implemented yet!";
	}
	else if (opt == 4) { // Save current ordering list
		std::string filepath = InputManager::get_instance().get_string("Enter filepath: ");
		auto q = OrderManager::get_instance().get_queue();
		for (const auto& el : q) {
			Logger::get_instance(filepath).log(el.to_string());
		}
	} else if (opt == 5) { // Logout
		return std::make_unique<LoginState>(LoginState{});
	} else if (opt == 6) { // Quit
		return std::make_unique<ExitState>(ExitState{});
	}
	return std::make_unique<MainState>(*this);
}	

std::unique_ptr<State> OrderState::handle_events() const {
	std::cout << "Please, fill out the ordering details: " << std::endl;

	std::string last_name = InputManager::get_instance().get_string("Enter your last name: ");

	// Menu for choosing type of order
	Menu order_kind_selection{"Select the order type", {
		"Photography",
		"Post-production",
		"Full service"
	}};

	order_kind_selection.render();
	int opt = order_kind_selection.get_option();

	OrderKind kind{};
	switch (opt) {
		case 1:
			kind = OrderKind::Photography;
			break;
		case 2:
			kind = OrderKind::PostProduction;
			break;
		case 3:
			kind = OrderKind::FullService;
			break;
		default:
			// Impossible case, check is ensured by Menu class
			std::cout << "Invalid choice. Returning to the ordering menu..." << std::endl;
			return std::make_unique<OrderState>(*this);
	}

	bool is_urgent = InputManager::get_instance().get_yes_or_no("Mark as urgent? (y/n): ");

	Order order{last_name, kind, is_urgent};
	OrderManager::get_instance().add_order(order);

	// Print the added data
	std::cout << "Added Order with the following information: " << std::endl;
	order.print();

	bool finished = InputManager::get_instance().get_yes_or_no("Stop ordering? (y/n): ");

	if (finished) {
		return std::make_unique<MainState>(MainState{});
	}

	return std::make_unique<OrderState>(*this);
}
