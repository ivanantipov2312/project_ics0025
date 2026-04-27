#ifndef ORDER_MANAGER_HPP_
#define ORDER_MANAGER_HPP_
#include "../core/Order.hpp"
#include <deque>

// Global static queue for orders
class OrderManager {
public:
	// Disallow any copying of objects of this class
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
	// Disallow manual construction of the objects (only through get_instance())
	OrderManager() {}
	~OrderManager() {}
	std::deque<Order> order_queue;
};

#endif // ORDER_MANAGER_HPP_
