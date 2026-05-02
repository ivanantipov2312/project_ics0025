#ifndef ORDER_STATE_HPP_
#define ORDER_STATE_HPP_
#include "State.hpp"

// Ordering loop
class OrderState : public State {
public:
	OrderState(const User& ordering_user) : ordering_user{ordering_user} {}
	void render() const override {}
	void handle_events(Context& ctx) const override;
private:
	User ordering_user;
};

#endif // ORDER_STATE_HPP_
