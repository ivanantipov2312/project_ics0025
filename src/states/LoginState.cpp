#include "LoginState.hpp"
#include "MainState.hpp"
#include "../managers/UserManager.hpp"

void LoginState::handle_events(Context& ctx) const {
	int opt = login_menu.get_option(ctx.input);
	if (opt == 1) { // Login
		std::string username = ctx.input.get_string("Username: ");
		const User* user = UserManager::get_instance().get_user(username);
		if (user == nullptr) {
			std::cout << "No such user exists! Register!" << std::endl;
			return;
		}

		int attempts = 0;
		while (attempts < 3) {
			std::string password = ctx.input.get_string("Password: ");
			if (user->password == password) {
				ctx.state.change(std::make_unique<MainState>(MainState{})); // If correct, transfer to the main state
				return; // Return early to exit the loop
			}
			std::cout << "Wrong password! (" << (attempts + 1) << "/3 attempts): " << std::endl;
			attempts++;
		}
	} else if (opt == 2) { // Register
		std::string username = ctx.input.get_string("Enter your username: ");
		if (UserManager::get_instance().get_user(username) != nullptr) {
			std::cout << "User with this username already exists!" << std::endl;
			return;
		}

		std::string email = ctx.input.get_string("Enter your email: ");
		std::string password = ctx.input.get_string("Enter your password: ");
		bool is_photographer = ctx.input.get_yes_or_no("Are you a photographer? ");
		User user = {username, email, password, is_photographer ? Role::Photographer : Role::Customer};
		UserManager::get_instance().add_user(user);
		ctx.state.change(std::make_unique<MainState>(MainState{}));
	} else if (opt == 3) { // Exit
		ctx.state.stop();
	}

}
