#include "GameEntity.hpp"

GameEntity::GameEntity() : x_(0), y_(0), active_(false)
{
}

GameEntity::GameEntity(int x, int y) : x_(x), y_(y), active_()
{}

GameEntity::GameEntity(int x, int y, bool isActive) : x_(x), y_(y), active_(isActive)
{}

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


