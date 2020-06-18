#include "include/RenderingSystem.h"


RenderingSystem::RenderingSystem()
{
}

RenderingSystem::~RenderingSystem()
{
}

sf::Texture* RenderingSystem::LoadTexture(std::string texture)
{	
	// Create a pointer (by using "new", remember to "delete" after!)
	sf::Texture* tex = new sf::Texture();

	if (!tex->loadFromFile(texture))
	{
		// /n = line break
		std::cerr << "Unable to load image " << texture << "./nIs this image in the correct directory?" << std::endl;
		std::cerr << "Error: " << std::endl;

		system("pause");

		exit(EXIT_FAILURE);
	}

	return tex;
}

void RenderingSystem::tick(ECS::World* world, float deltaTime)
{
	// Clear before drawing all textures;
	Engine::GetInstance().window->clear();

	// Lambda Function
	// Pass a function to some other function (this is used once)
	// Each() takes in one anonymous function passing it by reference (&)
	// Pass in the components by their structs/classes (<>)
	world->each<Transform, Sprite>(
		[&](ECS::Entity* entity,
			ECS::ComponentHandle<Transform> transform,
			ECS::ComponentHandle<Sprite> sprite) -> void
	{
		// Pass in our entity, as well as our components

		// Add texture to map (list) if there's a free spot
		if (textureMap.count(sprite->texture) < 1)
		{
			textureMap[sprite->texture] = LoadTexture(sprite->texture);
		}

		// If the texture is not found, then add it
		if (sprite->sprite.getTexture() == NULL)
		{
			// *dereference the pointer
			sprite->sprite.setTexture(*textureMap[sprite->texture]);

			// Set the sprite's size bounds
			sprite->width = sprite->sprite.getGlobalBounds().width;
			sprite->height = sprite->sprite.getGlobalBounds().height;
		}

		// Update and draw to the screen
		sprite->sprite.setPosition(transform->X, transform->Y);
		Engine::GetInstance().window->draw(sprite->sprite);
	});

	// Display updates
	Engine::GetInstance().window->display();
}