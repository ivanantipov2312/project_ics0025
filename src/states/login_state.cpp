#include "login_state.h"
#include "main_state.h"

void LoginState::handle_events(StateManager& manager) const {
	int opt = login_menu.get_option();
	if (opt == 1) { // Login
		std::string username = InputManager::get_instance().get_string("Username: ");
		const User* user = UserManager::get_instance().get_user(username);
		if (user == nullptr) {
			std::cout << "No such user exists! Register!" << std::endl;
			return;
		}

		int attempts = 0;
		while (attempts < 3) {
			std::string password = InputManager::get_instance().get_string("Password: ");
			if (user->password == password) {
				manager.change(std::make_unique<MainState>(MainState{})); // If correct, transfer to the main state
			}
			std::cout << "Wrong password! (" << (attempts + 1) << "/3 attempts): " << std::endl;
			attempts++;
		}
	} else if (opt == 2) { // Register
		std::string username = InputManager::get_instance().get_string("Enter your username: ");
		if (UserManager::get_instance().get_user(username) != nullptr) {
			std::cout << "User with this username already exists!" << std::endl;
			return;
		}

		std::string email = InputManager::get_instance().get_string("Enter your email: ");
		std::string password = InputManager::get_instance().get_string("Enter your password: ");
		bool is_photographer = InputManager::get_instance().get_yes_or_no("Are you a photographer? ");
		User user = {username, email, password, is_photographer ? Role::Photographer : Role::Customer};
		UserManager::get_instance().add_user(user);
		manager.change(std::make_unique<MainState>(MainState{}));
	} else if (opt == 3) { // Exit
		manager.stop();
	}

}
