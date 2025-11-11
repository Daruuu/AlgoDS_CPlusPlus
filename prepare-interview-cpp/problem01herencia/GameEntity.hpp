#ifndef ALGODS_CPLUSPLUS_GAMEENTITY_HPP
#define ALGODS_CPLUSPLUS_GAMEENTITY_HPP
class GameEntity
{
public:
	GameEntity();
	GameEntity(int x, int y);
	virtual ~GameEntity();	//obligatorio cuando herencia

	//	pure virtual (obligatorio a override en herencia)
	virtual void update() = 0;
	virtual void render() = 0;

	int getX() const;
	int getY() const;
	bool isActive() const;

protected:
	int x_;
	int y_;
	bool active_;
};

#endif //ALGODS_CPLUSPLUS_GAMEENTITY_HPP