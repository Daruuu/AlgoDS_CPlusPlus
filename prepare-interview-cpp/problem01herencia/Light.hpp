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

	void update() override;
	void render() override;

};

#endif //ALGODS_CPLUSPLUS_LIGHT_HPP