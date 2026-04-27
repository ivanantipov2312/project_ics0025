#ifndef CONTEXT_HPP_
#define CONTEXT_HPP_
#include "../io/InputManager.hpp"
#include "../states/StateManager.hpp"

struct Context {
	InputManager input{};
	StateManager state{};
};

#endif // CONTEXT_HPP_
