#ifndef USER_H_
#define USER_H_
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
	};
}

struct User {
	std::string username{};
	std::string email{};
	std::string password{}; // TODO: Implement simple hashing
	Role role{Role::Customer};
};

#endif // USER_H_
