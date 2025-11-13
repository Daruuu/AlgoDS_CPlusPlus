#include "Button.hpp"

#include <iostream>

Button::Button() : GameEntity()
{}

Button::Button(int x, int y) : GameEntity(x, y)
{}

Button::~Button()
{
}

void Button::onClick()	// only button
{
	std::cout << "Button clicked!\n" << std::endl;
}

//	override
void Button::update()
{
	std::cout << "update button!\n" << std::endl;
}
void Button::render()
{
	std::cout << "Render Button!\n" << std::endl;
}
