#ifndef CONTEXT_HPP_
#define CONTEXT_HPP_
#include "../io/InputManager.hpp"
#include "../states/StateManager.hpp"
#include "../order/OrderManager.hpp"
#include "../user/UserManager.hpp"

struct Context {
	InputManager input{};
	StateManager state{};
	OrderManager order_queue{};
	UserManager users{};
};

#endif // CONTEXT_HPP_
