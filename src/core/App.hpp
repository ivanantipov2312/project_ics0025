#ifndef APP_HPP_
#define APP_HPP_
#include "../states/State.hpp"
#include "../states/LoginState.hpp"
#include "../managers/StateManager.hpp"

class App {
public:
	void run() {
		manager.change(std::make_unique<LoginState>(LoginState{}));
		while (manager.is_running()) {
			manager.get()->render();
			manager.get()->handle_events(manager);
		}
	}
private:
	StateManager manager{};
};

#endif // APP_HPP_
