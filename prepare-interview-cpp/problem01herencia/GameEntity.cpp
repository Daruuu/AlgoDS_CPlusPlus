#include "GameEntity.hpp"

GameEntity::GameEntity() : x_(0), y_(0), active_(true)
{
}

GameEntity::~GameEntity()
{
}

int GameEntity::getX() const
{
	return x_;
}

int GameEntity::getY() const
{
	return y_;
}

bool GameEntity::isActive() const
{
	return active_;
}


