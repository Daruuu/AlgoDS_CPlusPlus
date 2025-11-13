#ifndef ALGODS_CPLUSPLUS_BUTTON_HPP
#define ALGODS_CPLUSPLUS_BUTTON_HPP
#include "GameEntity.hpp"

class Button : public GameEntity
{
public:
	Button();
	Button(int x, int y);
	~Button();

	void onClick();	// only button

	//	override
	void update();
	void render();
};
#endif //ALGODS_CPLUSPLUS_BUTTON_HPP