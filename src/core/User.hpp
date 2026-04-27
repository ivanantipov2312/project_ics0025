#ifndef USER_HPP_
#define USER_HPP_
#include <string>

enum class Role {
	Admin,
	Photographer,
	Customer,
};

inline std::string role_to_string(Role r) {
	switch (r) {
		case Role::Admin: return "Admin";
		case Role::Customer: return "Customer";
		case Role::Photographer: return "Photographer";
		default: return "Unknown";
	};
}

inline Role string_to_role(const std::string& role) {
	if (role == "Admin") {
		return Role::Admin;
	}
	if (role == "Photographer") {
		return Role::Photographer;
	}
	return Role::Customer; // Every unkown role will be treated as customer
}

struct User {
	std::string username{};
	std::string email{};
	std::string password{}; // TODO: Implement simple hashing
	Role role{Role::Customer};
};

#endif // USER_HPP_
