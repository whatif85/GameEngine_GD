#include "include/AnimationSystem.h"


AnimationSystem::AnimationSystem()
{

}

AnimationSystem::~AnimationSystem()
{
}

void AnimationSystem::tick(ECS::World* world, float deltaTime)
{
	world->each<Animator, Sprite>(
		[&](ECS::Entity* entity,
			ECS::ComponentHandle<Animator> animator,
			ECS::ComponentHandle<Sprite> sprite) -> void
	{
		animator->currentTime += deltaTime;

		if (animator->currentTime >= animator->nextFrameTime)
		{
			animator->currentTime = 0;
			animator->currentColumn = (animator->currentColumn + 1) % 4; // hardcoded value;
		}

		sprite->sprite.setTextureRect(
			sf::IntRect(animator->currentColumn *animator->spriteWidth, // rect X
				animator->currentRow *animator->spriteHeight,			// rect Y
				animator->spriteWidth,									// width
				animator->spriteHeight));								// height
	});
}
