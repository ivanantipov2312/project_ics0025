#ifndef APP_HPP_
#define APP_HPP_
#include "../states/State.hpp"
#include "../states/LoginState.hpp"
#include "Context.hpp"

class App {
public:
	void run() {
		ctx.state.change(std::make_unique<LoginState>(LoginState{}));
		while (ctx.state.is_running()) {
			ctx.state.get()->render();
			ctx.state.get()->handle_events(ctx);
		}
	}
private:
	Context ctx{};
};

#endif // APP_HPP_
