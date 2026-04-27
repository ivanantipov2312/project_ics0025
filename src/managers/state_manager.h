#ifndef STATE_MANAGER_H_
#define STATE_MANAGER_H_
#include <memory>

class State;

class StateManager {
public:
	StateManager(std::unique_ptr<State> initial) : current(std::move(initial)) {}
	void change(std::unique_ptr<State> s) {
		current = std::move(s);
	}

	State* get() const {
		return current.get();
	}

	void stop() {
		running = false;
	}

	bool is_running() const {
		return running;
	}
private:
	std::unique_ptr<State> current = nullptr;
	bool running = true;
};

#endif // STATE_MANAGER_H_
