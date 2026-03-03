#ifndef STATE_H_
#define STATE_H_
#include "menu.h"
#include <memory>

class State {
public:
	virtual std::unique_ptr<State> handle_events() = 0;
	virtual void render() = 0;
};

class ExitState : public State {
public:
	void render() override {}
	std::unique_ptr<State> handle_events() override { return nullptr; }
};

class MainState : public State {
public:
	void render() override {
		menu.render();
	}

	std::unique_ptr<State> handle_events() override {
		int opt = menu.get_option();
		if (opt == 4) {
			return std::make_unique<ExitState>(ExitState{});
		}
		return std::make_unique<MainState>(*this);
	}
private:
	MainMenu menu{};
};

#endif // STATE_H_
