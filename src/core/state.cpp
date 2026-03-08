#include "state.h"
#include "../managers/order_mananger.h"
#include "../managers/logger.h"
#include "../managers/input_manager.h"

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
	} else if (opt == 5) { // Quit
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
