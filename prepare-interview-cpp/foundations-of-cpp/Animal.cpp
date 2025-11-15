#include "Animal.hpp"

Animal::Animal() : type_("[animal default]")
{
	std::cout << "constructor of animal\n";
}

Animal::Animal(const Animal& other) : type_(other.type_)
{
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		type_ = other.type_;
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout << "destructor of ~animal()\n";
}

std::string Animal::getType() const
{
	return this->type_; 
}

void Animal::setType(const std::string type)
{
	this->type_ = type;
}

void Animal::makeSound()
{
	std::cout << "sound of animal\n";
}
