#include "order_state.h"
#include "main_state.h"

void OrderState::handle_events(StateManager& manager) const {
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
		return;
	}

	bool is_urgent = InputManager::get_instance().get_yes_or_no("Mark as urgent? (y/n): ");

	Order order{last_name, kind, is_urgent};
	OrderManager::get_instance().add_order(order);

		// Print the added data
	std::cout << "Added Order with the following information: " << std::endl;
	order.print();

	bool finished = InputManager::get_instance().get_yes_or_no("Stop ordering? (y/n): ");

	if (finished) {
		manager.change(std::make_unique<MainState>(MainState{}));
	}
}
