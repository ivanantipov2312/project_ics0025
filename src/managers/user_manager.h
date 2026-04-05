#ifndef User_MANAGER_H_
#define User_MANAGER_H_
#include "../core/user.h"
#include "../io/file_reader.h"
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
		reader.csv_write_row({user.username, user.email, user.password, role_to_string(user.role)});
	}

	const User* get_user(const std::string& username) {
		if (users.find(username) == users.end()) {
			return nullptr;
		}
		return &users.at(username);
	}
private:
	// Disallow manual construction of the objects (only through get_instance())
	UserManager() {
		auto rows = reader.csv_get_rows();
		for (const auto& row : rows) {
			if (row.size() == 4) {
				users.insert({
					row.at(0),
					{row.at(0), row.at(1), row.at(2), string_to_role(row.at(3))}
				});
			}
		}
	}
	~UserManager() {}
	std::map<std::string, User> users{};
	FileReader reader{"../users.csv", {"Username", "Email", "Password","Role"}};
};

#endif // USER_MANAGER_H_
