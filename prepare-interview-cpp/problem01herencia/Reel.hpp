#ifndef ALGODS_CPLUSPLUS_REEL_HPP
#define ALGODS_CPLUSPLUS_REEL_HPP
#include "GameEntity.hpp"

class Reel : public GameEntity
{
public:
	Reel(int x, int y);
	~Reel();

	void spin();
	//	from game entity
	void update() override;
	void render() override;
};

#endif //ALGODS_CPLUSPLUS_REEL_HPP