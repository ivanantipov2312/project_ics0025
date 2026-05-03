#include "MainState.hpp"
#include "OrderState.hpp"
#include "LoginState.hpp"

void MainState::handle_events(Context& ctx) const {
	int opt = menu.get_option(ctx.input);
	if (opt == 1) { // Order
		ctx.state.change(std::make_unique<OrderState>(OrderState{current_user}));
	} else if (opt == 2) { // List orders
		try {
			auto q = ctx.order_queue.get_orders_from_user(current_user.user_id);
			std::cout << "Your orders: " << std::endl;
			for (const auto& el : q) {
				el.print();
			}
		} catch (NoOrdersFoundException& e) {
			std::cout << "No orders!" << std::endl;
			ctx.logger.log(LogLevel::Error, "Display failed: no orders found");
		}
	} else if (opt == 3) { // List photographers
		auto photographers = ctx.users.get_users_by_role(Role::Photographer);
		for (const auto& el : photographers) {
			std::cout << el.username << " | " << el.email << std::endl;
		}
	}
	else if (opt == 4) { // Save current ordering list
		try {
			auto q = ctx.order_queue.get_orders_from_user(current_user.user_id);
			std::string filepath = ctx.input.get_string("Enter filepath: ");
			FileReader reader{filepath, {}};
			for (const auto& el : q) {
				reader.csv_write_row({});
			}
		} catch (NoOrdersFoundException& e) {
			std::cout << "No orders to save!" << std::endl;
			ctx.logger.log(LogLevel::Error, "File save failed: no orders in the queue");
		}
	} else if (opt == 5) { // Logout
		ctx.state.change(std::make_unique<LoginState>(LoginState{}));
	} else if (opt == 6) { // Quit
		ctx.state.stop();
	}
}
