#ifndef LOGIN_STATE_HPP_
#define LOGIN_STATE_HPP_
#include "State.hpp"
#include "../io/Menu.hpp"

// State for logging in
class LoginState : public State {
public:
	void render() const override {
		login_menu.render();
	}

	void handle_events(Context& ctx) const override;
private:
	Menu login_menu{"Login", {
		"Login",
		"Register",
		"Quit"
	}};
};

#endif // LOGIN_STATE_HPP_
