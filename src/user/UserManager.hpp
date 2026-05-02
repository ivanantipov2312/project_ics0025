#ifndef User_MANAGER_HPP_
#define User_MANAGER_HPP_
#include "User.hpp"
#include "../io/FileReader.hpp"
#include "../crypto/djb2.hpp"
#include <map>

// Global queue for users
class UserManager {
public:
	UserManager() {
		auto rows = reader.csv_get_rows();
		for (const auto& row : rows) {
			if (row.size() == 5) {
				users.insert({
					row.at(0), {
						std::stoi(row.at(0)), // ID
						row.at(1), // Uername
						row.at(2), // Email
						std::stoul(row.at(3)), // PasswordHash
						string_to_role(row.at(3)) // Role
					}
				});
			}
		}
	}
	~UserManager() {}

	const User& add_user(const std::string& username, const std::string& email, const std::string& password, Role role) {
		uint64_t pw_hash = hasher.get_str_hash(password);

		User user{
			next_id,
			username,
			email,
			pw_hash,
			role,
		};

		auto inserted = users.insert({user.username, user});
		reader.csv_write_row({
			std::to_string(next_id),
			user.username,
			user.email,
			std::to_string(user.password_hash),
			role_to_string(user.role)
		});

		next_id++;
		return inserted.first->second;
	}

	const User* get_user(const std::string& username) {
		if (users.find(username) == users.end()) {
			return nullptr;
		}
		return &users.at(username);
	}

	bool verify_user_password(const User* u, const std::string& password) const {
		return hasher.verify_password(password, u->password_hash);
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
	int next_id{};
	FileReader reader{"./users.csv", {
		"ID",
		"Username",
		"Email",
		"PasswordHash",
		"Role"
	}};
	DJB2Hasher hasher{5851};
};

#endif // USER_MANAGER_HPP_
