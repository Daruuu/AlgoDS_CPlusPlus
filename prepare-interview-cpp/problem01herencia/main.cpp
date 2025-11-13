#include <vector>
#include <iostream>

#include "GameEntity.hpp"
#include "Reel.hpp"
#include "Button.hpp"
#include "Light.hpp"

typedef std::vector<GameEntity*> vectorGameEntity;

int main()
{
	vectorGameEntity entities;

	entities.push_back(new Reel(100, 200));
	entities.push_back(new Button(300, 400));
	entities.push_back(new Light(500, 600));

	vectorGameEntity::iterator it;

	for (it = entities.begin(); it != entities.end(); ++it)
	{
		GameEntity* e = *it;
		e->update();
		e->render();
	}
	static_cast<Reel*>(entities[0])->spin();
	static_cast<Button*>(entities[1])->onClick();
	static_cast<Light*>(entities[2])->blink();

	for (vectorGameEntity::iterator it = entities.begin(); it != entities.end(); ++it)
	{
		delete *it;
	}

	/*
	for (auto e : entities)
	{
		delete[] e;
	}
	*/

	return 0;
}
