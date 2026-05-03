#ifndef ORDER_MANAGER_HPP_
#define ORDER_MANAGER_HPP_
#include "Order.hpp"
#include "../io/FileReader.hpp"
#include <vector>
#include <exception>

class OrderNotFound : public std::exception {
public:
	const char* what() const noexcept override {
		return "OrderNotFound";
	}
};

class NoOrdersFoundException : public std::exception {
public:
	const char* what() const noexcept override {
		return "NoOrdersFound";
	}
};

// Global static queue for orders
class OrderManager {
public:
	OrderManager() {
		auto rows = reader.csv_get_rows();
		for (const auto& row : rows) {
			if (row.size() == 5) {
				orders.push_back({
					std::stoi(row.at(0)), // ID
					row.at(1), // Customer Last Name
					std::stoi(row.at(2)), // User ID
					string_to_order_kind(row.at(3)), // Kind
					row.at(4) == "Y", // Is urgent
					std::stoi(row.at(5)), // Photographer ID
					row.at(6) == "Y", // Is completed
				});
			}
		}

		next_id = orders.size() + 1;
	}

	void take_order(int photographer_id, int order_id) {
		for (auto& o : orders) {
			if (o.order_id == order_id) {
				o.photographer_id = photographer_id;
				return;
			}
		}
	}

	void add_order(const std::string& last_name, int user_id, OrderKind kind, bool is_urgent) {
		Order order{next_id, last_name, user_id, kind, is_urgent};
		orders.push_back(order);
		reader.csv_write_row({
			std::to_string(order.order_id),
			order.customer_last_name,
			std::to_string(order.user_id),
			order_kind_to_string(order.kind),
			order.is_urgent ? "Y" : "N",
			std::to_string(order.photographer_id),
			order.is_completed ? "Y" : "N"
		});
		next_id++;
	}

	std::vector<Order> get_orders_from_photographer(int photographer_id) const {
		std::vector<Order> ret{};
		for (const auto& o : orders) {
			if (o.photographer_id == photographer_id) {
				ret.push_back(o);
			}
		}

		if (ret.empty()) {
			throw NoOrdersFoundException{};
		}

		return ret;
	}

	const std::vector<Order> get_orders_from_user(int user_id) const {
		std::vector<Order> ret{};
		for (const auto& o : orders) {
			if (o.user_id == user_id) {
				ret.push_back(o);
			}
		}

		if (ret.empty()) {
			throw NoOrdersFoundException{};
		}

		return ret;
	}

	const std::vector<Order>& get_queue() const {
		if (orders.empty()) {
			throw NoOrdersFoundException{};
		}
		return orders;
	}
private:
	std::vector<Order> orders;
	FileReader reader{"orders.csv", {
		"ID",
		"Customer Last Name",
		"User ID",
		"Kind",
		"Urgent",
		"Photographer ID",
		"Completed"
	}};
	int next_id = 1;
};

#endif // ORDER_MANAGER_HPP_
