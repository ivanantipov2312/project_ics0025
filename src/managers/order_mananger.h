#ifndef ORDER_MANAGER_H_
#define ORDER_MANAGER_H_
#include "../core/order.h"
#include <deque>

class OrderManager {
public:
	OrderManager(const OrderManager&) = delete;
	OrderManager& operator=(const OrderManager&) = delete;

	static OrderManager& get_instance() {
		static OrderManager instance{};
		return instance;
	}

	void add_order(const Order& order) {
		order_queue.push_back(order);
	}

	const std::deque<Order>& get_queue() const {
		return order_queue;
	}

	Order& pop_order() {
		Order& current_item = order_queue.front();
		order_queue.pop_front();
		return current_item;
	}
private:
	OrderManager() {}
	~OrderManager() {}
	std::deque<Order> order_queue;
};

#endif // ORDER_MANAGER_H_
