#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

class Animal
{
	// private:
	// 	std::string type_;

protected:
	std::string type_;

public:
	Animal();
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
	virtual ~Animal();

	//	methods
	std::string getType() const;
	void setType(const std::string type);
	virtual void makeSound();
};
#endif
