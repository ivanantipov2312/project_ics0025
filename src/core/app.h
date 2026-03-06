#ifndef APP_H_
#define APP_H_
#include <iostream>
#include <memory>
#include "menu.h"
#include "state.h"

class App {
public:
	void run() {
		while (is_running) {
			current_state->render();
			auto next_state = current_state->handle_events();
			if (!next_state) {
				is_running = false;
			}

			current_state = std::move(next_state);
		}
	}
private:
	std::unique_ptr<State> current_state = std::make_unique<MainState>(MainState{});
	bool is_running = true;
};

#endif // APP_H_
