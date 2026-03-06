#ifndef ORDER_H_
#define ORDER_H_
#include <string>
#include <iostream>

enum class OrderKind {
	Photography,
	PostProduction,
	FullService,
};

// TODO: Add more details/data
// TODO: Add some global or static queue
struct Order {
	std::string customer_last_name{};
	OrderKind kind{};
	bool is_urgent{false};

	void print() const {
		std::cout << "Order details: " << std::endl;
		std::cout << "Customer's last name: " << customer_last_name << std::endl;
		std::cout << "Order kind: ";
		switch (kind) {
		case OrderKind::Photography:
			std::cout << "Photography";
			break;
		case OrderKind::PostProduction:
			std::cout << "Post-production";
			break;
		case OrderKind::FullService:
			std::cout << "Full service";
			break;
		}
		std::cout << std::endl;
	}
};

#endif // ORDER_H_
