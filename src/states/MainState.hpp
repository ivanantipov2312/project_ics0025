#ifndef MAIN_STATE_HPP_
#define MAIN_STATE_HPP_
#include "State.hpp"
#include "../io/Menu.hpp"

// Main loop
class MainState : public State {
public:
	MainState(const User& current_user) : current_user{current_user} {}

	void render() const override {
		menu.render();
	}

	void handle_events(Context& ctx) const override;
private:
	Menu menu{"Main Menu", {
		"Place an order",
		"See current orders from you",
		"List all photographers",
		"Save your current list of orders",
		"Logout",
		"Quit"
	}};

	User current_user;
};

#endif // !MAIN_STATE_HPP_
