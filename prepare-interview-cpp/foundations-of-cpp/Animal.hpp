#include <iostream>

class Animal
{

	private:
		std::string type_;

	protected:

	public:
		Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		~Animal();

	//	methods
	std::string getType() const;
	void setType(const std::string type);
	void makesound();
};
