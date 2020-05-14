#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>


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
};

