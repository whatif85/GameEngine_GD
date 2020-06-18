#pragma once

#include "ECS.h"
#include "Engine.h"
#include "Components.h"


class RenderingSystem : public ECS::EntitySystem
{
private:
	std::unordered_map<std::string, sf::Texture*> textureMap;
	sf::Texture* LoadTexture(std::string texture);

public:
	RenderingSystem();
	~RenderingSystem();

	void tick(ECS::World* world, float deltaTime) override;
};

