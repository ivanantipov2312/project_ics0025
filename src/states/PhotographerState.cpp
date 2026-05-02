#include "PhotographerState.hpp"

void PhotographerState::handle_events(Context& ctx) const {
	int option = menu.get_option(ctx.input);

	if (option == 1) { // See orders
		auto orders = ctx.order_queue.get_queue();
		for (const auto& o : orders) {
			o.print();
		}
	} else if (option == 2) { // Take order

	} else if (option == 3) {
	}
}
