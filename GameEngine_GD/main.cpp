// Game Main

#include <SFML/Graphics.hpp>
#include "include/Engine.h"


int main(int argc, char* args[])
{
	// Declare and get instance of singleton
	Engine& gameEngine = Engine::GetInstance();

	sf::RenderWindow window(sf::VideoMode(800, 600), "Game");

	// Create the world for attaching entities and systems to
	gameEngine.world = ECS::World::createWorld();
	ECS::Entity* ent;

	// Add systems to the engine
	gameEngine.AddSystem(new RenderingSystem());

	// Create and assign 250 entities to the world
	for (int i = 0; i < 35; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			// Create entities in the world from the GE
			ent = gameEngine.world->create();

			// Assign components to entities after creation
			// sprite size
			ent->assign<Transform>(i * 32, j * 32);
			ent->assign<Sprite>("../Debug/Images/herosheet.png");
			ent->assign<Animator>(32, 32, 200.f);
			std::cout << ent->getEntityId() << " is the entity ID." << std::endl;
		}
	}

	// Pass window reference to engine and start
	gameEngine.Start(&window); // this later calls updates

	return 0;
}