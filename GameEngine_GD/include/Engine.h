#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "ECS.h"
#include "Components.h"
#include "RenderingSystem.h"
// TODO: Remember to do the same with the other systems!!!


class Engine
{
private:
	bool quit;

	Engine(void);
	~Engine(void);

	void Update();

	// Required to prevent the reference from being copied, moved, or assigned
	Engine(Engine& copy);	// Stop copying the constructor
	Engine(Engine&& other);	// Stop move constructor
	Engine& operator= (Engine& copy);  // Hide assignment operator

public:
	static Engine& GetInstance(void);

	void Start(sf::RenderWindow* win);

	sf::RenderWindow* window;

	ECS::World* world;

	void AddSystem(ECS::EntitySystem* newSys);
};

