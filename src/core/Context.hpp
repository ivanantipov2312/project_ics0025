#ifndef CONTEXT_HPP_
#define CONTEXT_HPP_
#include "../io/InputManager.hpp"
#include "../states/StateManager.hpp"
#include "../order/OrderManager.hpp"
#include "../user/UserManager.hpp"
#include "../io/Logger.hpp"

struct Context {
	InputManager input{};
	StateManager state{};
	OrderManager order_queue{};
	UserManager users{};
	Logger logger{"log.txt"};
};

#endif // CONTEXT_HPP_
