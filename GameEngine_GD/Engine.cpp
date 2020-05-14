#include "Engine.h"


Engine::Engine(void)
{

}

Engine::~Engine()
{

}

Engine& Engine::GetInstance(void)
{
	// Space for this instance has already been allocated
	static Engine instance;

	return instance;
}

void Engine::Start(sf::RenderWindow* win)
{
	quit = false;
	window = win;

	while (window->isOpen())
	{
		Update();
	}
}

void Engine::Update()
{
	sf::Event event;

	while (window->pollEvent(event))
	{
		// "close requested" event: we close the window
		if (event.type == sf::Event::Closed || quit)
		{
			window->close();
		}
	}

	
}