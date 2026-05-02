#ifndef DJB2_HPP_
#define DJB2_HPP_
#include <string>
#include <cstdint>

class DJB2Hasher {
public:
	DJB2Hasher(uint64_t init) : init_hash{init} {}

	uint64_t get_str_hash(const std::string& s) const {
		uint64_t hash = init_hash;
		for (const auto& c : s) {
			hash = ((hash << 5) + hash) + static_cast<int>(c);
		}
		return hash;
	}

	bool verify_password(const std::string& password, uint64_t hash) const {
		return get_str_hash(password) == hash;
	}
private:
	uint64_t init_hash{};
};

#endif // DJB2_HPP_
