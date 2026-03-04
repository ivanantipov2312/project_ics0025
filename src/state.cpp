#include "state.h"

std::unique_ptr<State> MainState::handle_events() const {
	int opt = menu.get_option();
	if (opt == 1) {
		return std::make_unique<OrderState>(OrderState{});
	}
	if (opt == 4) {
		return std::make_unique<ExitState>(ExitState{});
	}
	return std::make_unique<MainState>(*this);
}	

std::unique_ptr<State> OrderState::handle_events() const {
	std::string last_name = InputManager::get_instance().get_string("Enter your last name");
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
			std::cout << "Invalid choice. Returning to the ordering menu..." << std::endl;
			return std::make_unique<OrderState>(*this);
	}

	bool finished = InputManager::get_instance().get_yes_or_no("");

	if (finished) {
		return std::make_unique<MainState>(MainState{});
	}

	return std::make_unique<OrderState>(*this);
}
