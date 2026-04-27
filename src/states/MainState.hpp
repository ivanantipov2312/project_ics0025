#ifndef MAIN_STATE_HPP_
#define MAIN_STATE_HPP_
#include "State.hpp"
#include "../io/Menu.hpp"

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

#endif // !MAIN_STATE_HPP_
