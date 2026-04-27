#ifndef ORDER_STATE_HPP_
#define ORDER_STATE_HPP_
#include "State.hpp"

// Ordering loop
class OrderState : public State {
public:
	void render() const override {}
	void handle_events(StateManager& manager) const override;
};

#endif // ORDER_STATE_HPP_
