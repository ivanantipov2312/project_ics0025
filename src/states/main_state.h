#ifndef MAIN_STATE_H_
#define MAIN_STATE_H_
#include "state.h"
#include "order_state.h"
#include "login_state.h"
#include "../managers/logger.h"

// TODO: Add special menu for photographer
// Main loop
class MainState : public State {
public:
	void render() const override {
		menu.render();
	}

	void handle_events(StateManager& manager) const override;
private:
	Menu menu{"Main Menu", {
		"Place an order",
		"See current orders from you",
		"List all photographers",
		"Save your current list of orders",
		"Logout",
		"Quit"
	}};
};

#endif // !MAIN_STATE_H_
