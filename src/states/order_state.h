#ifndef ORDER_STATE_H_
#define ORDER_STATE_H_
#include "state.h"
#include "../core/order.h"
#include "../managers/order_mananger.h"

// Ordering loop
class OrderState : public State {
public:
	void render() const override {}
	void handle_events(StateManager& manager) const override;
};

#endif // ORDER_STATE_H_
