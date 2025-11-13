#ifndef ALGODS_CPLUSPLUS_LIGHT_HPP
#define ALGODS_CPLUSPLUS_LIGHT_HPP
#include "GameEntity.hpp"

class Light : public GameEntity
{
public:
	Light();
	Light(int x, int y);
	~Light();

	void blink();

	// from game entity
	void update() ;
	void render() ;

};

#endif //ALGODS_CPLUSPLUS_LIGHT_HPP