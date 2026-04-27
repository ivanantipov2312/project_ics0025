#ifndef STATE_HPP_
#define STATE_HPP_
#include "../core/Context.hpp"

// Basic interface for states
class State {
public:
	virtual ~State() {}

	// Every state must return either itself or other state.
	// The only state that returns nothins is ExitState
	virtual void handle_events(Context& ctx) const = 0;
	virtual void render() const = 0;
};

#endif // STATE_HPP_
