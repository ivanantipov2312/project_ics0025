#include "LoginState.hpp"
#include "MainState.hpp"
#include "PhotographerState.hpp"

void LoginState::handle_events(Context& ctx) const {
	int opt = login_menu.get_option(ctx.input);
	if (opt == 1) { // Login
		std::string username = ctx.input.get_string("Username: ");
		try {
			const User& user = ctx.users.get_user(username);

			int attempts = 0;
			while (attempts < 3) {
				std::string password = ctx.input.get_string("Password: ");
				if (ctx.users.verify_user_password(user, password)) {
					if (user.role == Role::Customer) {
						ctx.state.change(std::make_unique<MainState>(MainState{user}));
					} else {
						ctx.state.change(std::make_unique<PhotographerState>(PhotographerState{user}));
					}
					ctx.logger.log(LogLevel::Info, "Logged in");
					return; // Return early to exit the loop
				}
				std::cout << "Wrong password! (" << (attempts + 1) << "/3 attempts): " << std::endl;
				attempts++;
			}
		} catch (const UserNotFoundException& e) {
			std::cout << "User with this username does not exist!" << std::endl;
			ctx.logger.log(LogLevel::Error, "Login failed: User not found");
			return;
		}
	} else if (opt == 2) { // Register
		std::string username = ctx.input.get_string("Enter your username: ");
		std::string email = ctx.input.get_string("Enter your email: ");
		std::string password = ctx.input.get_string("Enter your password: ");
		bool is_photographer = ctx.input.get_yes_or_no("Are you a photographer? ");

		try {
			auto u = ctx.users.add_user(username, email, password, is_photographer ? Role::Photographer : Role::Customer);
			if (u.role == Role::Customer) {
				ctx.state.change(std::make_unique<MainState>(MainState{u}));
			} else {
				ctx.state.change(std::make_unique<PhotographerState>(PhotographerState{u}));
			}
		} catch (const UserAlreadyExistsException& e) {
			std::cout << "User with this name already exists!" << std::endl;
			ctx.logger.log(LogLevel::Error, "Register failed: User already exists");
			return;
		}
	} else if (opt == 3) { // Exit
		ctx.state.stop();
	}

}
