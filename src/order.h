#ifndef ORDER_H_
#define ORDER_H_
#include <string>

enum class OrderKind {
	Photography,
	PostProduction,
	FullService,
};

struct Order {
	std::string customer_last_name{};
	OrderKind kind{};
};

#endif // ORDER_H_
