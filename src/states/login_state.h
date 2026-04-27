#ifndef LOGIN_STATE_H_
#define LOGIN_STATE_H_
#include "state.h"
#include "../managers/user_manager.h"

// State for logging in
class LoginState : public State {
public:
	void render() const override {
		login_menu.render();
	}

	void handle_events(StateManager& manager) const override;
private:
	Menu login_menu{"Login", {
		"Login",
		"Register",
		"Quit"
	}};
};

#endif // LOGIN_STATE_H_
