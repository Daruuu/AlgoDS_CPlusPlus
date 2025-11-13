#include "Light.hpp"

#include <iostream>

Light::Light() : GameEntity()
{
}

Light::Light(int x, int y) : GameEntity(x, y)
{
}

Light::~Light()
{}

void Light::blink()
{
	std::cout << "Light blinking!" << std::endl;
}

// from game entity
void Light::update()
{
	std::cout << "parpadeo\n" << std::endl;
}

void Light::render()
{
	std::cout << "Render light\n" << std::endl;
}
