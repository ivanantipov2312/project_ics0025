#ifndef ORDER_HPP_
#define ORDER_HPP_
#include <string>
#include <iostream>

enum class OrderKind {
	Photography,
	PostProduction,
	FullService,
};

inline std::string order_kind_to_string(const OrderKind& kind) {
	switch (kind) {
		case OrderKind::Photography: return "Photography";
		case OrderKind::PostProduction: return "Post production";
		case OrderKind::FullService: return "Full service";
		default: return ""; // Impossible case, ensured by enum variants
	}
}

inline OrderKind string_to_order_kind(const std::string& kind) {
	if (kind == "Full Service") {
		return OrderKind::FullService;
	}

	if (kind == "Post production") {
		return OrderKind::PostProduction;
	}
		
	return OrderKind::Photography;
}

struct Order {
	int order_id{};
	std::string customer_last_name{};
	int user_id{};
	OrderKind kind{};
	bool is_urgent{false};

	int photographer_id{-1};
	bool is_completed{false};

	void print() const {
		std::cout << "Order details: " << std::endl;
		std::cout << "Customer's last name: " << customer_last_name << std::endl;
		std::cout << "Order kind: " << order_kind_to_string(kind) << std::endl;
		std::cout << "Is urgent? " << (is_urgent ? "Yes" : "No") << std::endl;
		std::cout << "Status: " << (is_completed ? "Completed" : "Pending") << std::endl;
	}

	std::string to_string() const {
		return "Order details:\n"
			"Customer's last name: " + customer_last_name + '\n' +
			"Order Kind: " + order_kind_to_string(kind) + '\n' +
			"Is urgent? " + (is_urgent ? "Yes" : "No") + '\n';
	}
};

#endif // ORDER_HPP_
