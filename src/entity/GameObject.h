#pragma once
#include <memory>
#include <SDL.h>
#include "../rendering/Transform.h"

class App;

class GameObject {
public:
	friend App;

	virtual void init() {}
	virtual void handleEvent(SDL_Event) {}
	virtual void process() {}
	virtual void draw() {}

protected:
	App* _parent = nullptr; // Set by App class
};

typedef std::shared_ptr<GameObject> GameObjPtr;
