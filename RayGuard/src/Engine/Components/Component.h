#pragma once

class Actor;

class Component {
protected:

	// Pointer to owner actor
	Actor* _owner;

	// Component is enabled or not
	bool m_enabled;

	// Component has started or not
	bool m_started;




public:
 
	Component(Actor* _owner = nullptr);
	~Component();
		
	


	bool Enabled() { return m_enabled; }
		
	virtual void OnEnable() { };

	virtual void OnDisable() { };

	virtual void Start() { m_started = true; }

	virtual void Update(double deltaTime);
	
	virtual void End( ) { }
	
	void Enabled(bool value);

};