#ifndef STATE_H_
#define STATE_H_
#include "../io/menu.h"
#include "../managers/state_manager.h"
#include <memory>

// Basic interface for states
class State {
public:
	virtual ~State() {}

	// Every state must return either itself or other state.
	// The only state that returns nothins is ExitState
	virtual void handle_events(StateManager& manager) const = 0;
	virtual void render() const = 0;
};

#endif // STATE_H_
