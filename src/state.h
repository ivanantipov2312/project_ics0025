#ifndef STATE_H_
#define STATE_H_
#include "menu.h"
#include "order.h"
#include <memory>

class State {
public:
	virtual std::unique_ptr<State> handle_events() const = 0;
	virtual void render() const = 0;
};

class ExitState : public State {
public:
	void render() const override {}
	std::unique_ptr<State> handle_events() const override { return nullptr; }
};

class MainState : public State {
public:
	void render() const override {
		menu.render();
	}
	std::unique_ptr<State> handle_events() const override;
private:
	MainMenu menu{};
};

class OrderState : public State {
public:
	void render() const override {}
	std::unique_ptr<State> handle_events() const override;
};

#endif // STATE_H_
