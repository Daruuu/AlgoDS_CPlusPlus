#include "Dog.hpp"

Dog::Dog()
{
	type_ = "Dog";
	std::cout << "constructor of dog" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

Dog::~Dog()
{
	std::cout << "destructor of dog" << std::endl;
}

void Dog::makeSound()
{
	std::cout << "sound of dog: guauuu" << std::endl;
}
