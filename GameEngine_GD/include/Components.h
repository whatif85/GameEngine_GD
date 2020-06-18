#pragma once

#include "ECS.h"
#include <SFML/Graphics.hpp>
#include <iostream>


struct Transform
{
public:
	ECS_DECLARE_TYPE;

	float X;
	float Y;
	float rotation;

	Transform(float x, float y)
	{
		X = x;
		Y = y;
		rotation = 0.f;
	}
};
ECS_DEFINE_TYPE(Transform);

struct Sprite
{
public:
	ECS_DECLARE_TYPE;

	int width;
	int height;

	sf::Sprite sprite;

	// store a string as a sort of pointer to a sprite
	std::string texture;

	Sprite(std::string spriteName)
	{
		// TODO: update manual
		texture = spriteName;
	}
};
ECS_DEFINE_TYPE(Sprite);

struct Animator
{
public:
	ECS_DECLARE_TYPE;

	int spriteWidth, spriteHeight;
	int currentColumn, currentRow;
	float currentTime, nextFrameTime;

	Animator(int width, int height, float timeBetweenFrames)
	{
		spriteWidth = width;
		spriteHeight = height;
		currentColumn = 0;
		currentRow = 0;
		nextFrameTime = timeBetweenFrames;
		currentTime = 0;
	}
};
ECS_DEFINE_TYPE(Animator);