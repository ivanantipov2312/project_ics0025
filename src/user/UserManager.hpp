#ifndef User_MANAGER_HPP_
#define User_MANAGER_HPP_
#include "User.hpp"
#include "../io/FileReader.hpp"
#include <map>

// Global queue for users
class UserManager {
public:
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

	const std::vector<User> get_users_by_role(Role role) {
		std::vector<User> res{};
		for (const auto& u : users) {
			if (u.second.role == role) {
				res.push_back(u.second);
			}
		}
		return res;
	}
private:
	std::map<std::string, User> users{};
	FileReader reader{"./users.csv", {"Username", "Email", "Password","Role"}};
};

#endif // USER_MANAGER_HPP_
