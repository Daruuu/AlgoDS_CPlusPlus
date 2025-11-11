#include "Reel.hpp"

#include <iostream>

#include "GameEntity.hpp"

Reel::Reel(int x, int y) : GameEntity(x, y)
{
}

Reel::~Reel()
{
}

void Reel::spin()
{
	std::cout << "Reel Spinning...\n";
}

void Reel::update()
{
	//	add update
}

void Reel::render()
{
	std::cout << "Render Reel at (" << x_ << "," << y_ << ")\n";
}
