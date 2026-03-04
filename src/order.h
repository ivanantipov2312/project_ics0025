#ifndef ORDER_H_
#define ORDER_H_
#include <string>

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
};

#endif // ORDER_H_
