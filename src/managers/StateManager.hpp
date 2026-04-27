#ifndef STATE_MANAGER_HPP_
#define STATE_MANAGER_HPP_
#include <memory>

class State;

class StateManager {
public:
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

#endif // STATE_MANAGER_HPP_
