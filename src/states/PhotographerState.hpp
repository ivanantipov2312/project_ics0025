#ifndef PHOTOGRAPHER_STATE_HPP_
#define PHOTOGRAPHER_STATE_HPP_
#include "State.hpp"
#include "../io/Menu.hpp"

class PhotographerState : public State {
public:
	void render() const override {
		menu.render();
	}

	void handle_events(Context& ctx) const override;
private:
	Menu menu{"Photographer:", {
		"See current orders",
		"Take an order",
		"Save orders"
	}};
};

#endif // PHOTOGRAPHER_STATE_HPP_
