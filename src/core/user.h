#ifndef USER_H_
#define USER_H_
#include <string>

enum class Role {
	Admin,
	Photographer,
	Customer,
};

struct User {
	std::string username{};
	std::string email{};
	std::string password{};
	Role role{Role::Customer};
};

#endif // USER_H_
