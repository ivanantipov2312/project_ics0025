#ifndef APP_H_
#define APP_H_
#include <iostream>
#include <memory>
#include "menu.h"
#include "../states/state.h"
#include "../states/login_state.h"
#include "../managers/state_manager.h"

class App {
public:
	void run() {
		StateManager manager{std::make_unique<LoginState>(LoginState{})};
		while (manager.is_running()) {
			manager.get()->render();
			manager.get()->handle_events(manager);
		}
	}
private:
};

#endif // APP_H_
