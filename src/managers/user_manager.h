#ifndef User_MANAGER_H_
#define User_MANAGER_H_
#include "../core/user.h"
#include <map>

// Global static queue for users
class UserManager {
public:
	// Disallow any copying of objects of this class
	UserManager(const UserManager&) = delete;
	UserManager& operator=(const UserManager&) = delete;

	static UserManager& get_instance() {
		static UserManager instance{};
		return instance;
	}

	void add_user(const User& user) {
		users.insert({user.username, user});
	}

	const User* get_user(const std::string& username) {
		if (users.find(username) == users.end()) {
			return nullptr;
		}
		return &users.at(username);
	}
private:
	// Disallow manual construction of the objects (only through get_instance())
	UserManager() {}
	~UserManager() {}
	std::map<std::string, User> users{};
};

#endif // USER_MANAGER_H_
