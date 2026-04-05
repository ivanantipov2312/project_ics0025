#ifndef STATE_H_
#define STATE_H_
#include "../io/menu.h"
#include "order.h"
#include <memory>

// Basic interface for states
class State {
public:
	// Every state must return either itself or other state.
	// The only state that returns nothins is ExitState
	virtual std::unique_ptr<State> handle_events() const = 0;
	virtual void render() const = 0;
};

// Final empty state for exit
class ExitState : public State {
public:
	void render() const override {}
	std::unique_ptr<State> handle_events() const override { return nullptr; }
};

class LoginState : public State {
public:
	void render() const override {
		login_menu.render();
	}

	std::unique_ptr<State> handle_events() const override;
private:
	Menu login_menu{"Login", {
		"Login",
		"Register",
		"Quit"
	}};
};

// TODO: Add special menu for photographer
// Main loop
class MainState : public State {
public:
	void render() const override {
		menu.render();
	}
	std::unique_ptr<State> handle_events() const override;
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

// Ordering loop
class OrderState : public State {
public:
	void render() const override {}
	std::unique_ptr<State> handle_events() const override;
};

#endif // STATE_H_
