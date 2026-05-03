#include "PhotographerState.hpp"
#include "LoginState.hpp"

void PhotographerState::handle_events(Context& ctx) const {
	int option = menu.get_option(ctx.input);

	if (option == 1) { // See orders
		try {
			auto orders = ctx.order_queue.get_queue();
			for (const auto& o : orders) {
				o.print();
			}
		} catch (NoOrdersFoundException& e) {
			std::cout << "No orders!" << std::endl;
			ctx.logger.log(LogLevel::Error, "Display failed: No orders found");
		}
	} else if (option == 2) { // Take order
		try {
			auto orders = ctx.order_queue.get_queue();

			std::cout << "Available orders:";
			for (const auto& o : orders) {
				o.print();
			}

			int order_id = ctx.input.get_int("Enter order ID: ", 1, orders.size());
			ctx.order_queue.take_order(photographer_user.user_id, order_id);
		} catch (NoOrdersFoundException& e) {
			std::cout << "No orders available!" << std::endl;
			ctx.logger.log(LogLevel::Error, "Taking order failed: No orders available");
		}
	} else if (option == 3) { // Save orders
		std::string filepath = ctx.input.get_string("Enter filepath: ");
		FileReader reader{filepath, {
			"ID",
			"Customer Last Name",
			"Kind",
			"Urgent",
		}};

		try {
			auto q = ctx.order_queue.get_orders_from_photographer(photographer_user.user_id);
			for (const auto& o : q) {
				reader.csv_write_row({std::to_string(o.order_id), o.customer_last_name, order_kind_to_string(o.kind), o.is_urgent ? "Y" : "N"});
			}
		} catch (NoOrdersFoundException& e) {
			std::cout << "No orders to save!" << std::endl;
			ctx.logger.log(LogLevel::Error, "Saving orders failed: No orders were found");
		}
	} else if (option == 4) { // Logout
		ctx.state.change(std::make_unique<LoginState>(LoginState{}));
	} else if (option == 5) { // Quit
		ctx.state.stop();
	}
}
