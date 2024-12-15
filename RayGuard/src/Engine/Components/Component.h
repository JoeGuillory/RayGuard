#pragma once

class Actor;

class Component {
protected:

	// Pointer to owner actor
	Actor* _owner;

	// Component is enabled or not
	bool _enabled;

	// Component has started or not
	bool _started;

public:


};