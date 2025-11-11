#include <iostream>
#include <vector>

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main()
{
	// TIP Press <shortcut actionId="RenameElement"/> when your caret is at the <b>lang</b> variable name to see how CLion can help you rename it.
	auto lang = "C++";
	std::cout << "Hello and welcome to " << lang << "!\n";

	/*
	for (int i = 1; i <= 5; i++)
	{
		// TIP Press <shortcut actionId="Debug"/> to start debugging your code. We have set one <icon src="AllIcons.Debugger.Db_set_breakpoint"/> breakpoint for you, but you can always add more by pressing <shortcut actionId="ToggleLineBreakpoint"/>.
		std::cout << "i = " << i << std::endl;
	}
	*/

	std::cout << "practice and understando pointer and memory pointer\n" << std::endl;
	std::string name = "daruny";
	std::string *pName = &name;
	int edad = 24;
	int *pEdad = &edad;

	std::cout << "Memory allocation of name: " << pName << "\n";
	std::cout << "Memory allocation of name: " << *pName;

	std::cout << "\nMemory allocation of edad: " << pEdad << "\n";
	std::cout << "Memory allocation of edad: " << *pEdad;


	std::cout << "\n++++++++ PRACTICE WITH REFERENCES: ++++++++\n" << std::endl;

	std::vector<std::string> fruits;

	fruits.push_back("Apple");
	fruits.push_back("Orange");
	fruits.push_back("Plum");
	fruits.push_back("Pear");

	std::string& firstFruitReference = fruits[0];
	std::string* firstFruitPointer = &fruits[0];

	fruits.push_back("Grapefruit");

	std::cout << "Print memory direction of firstFruitsReference[0]: " << firstFruitPointer << std::endl;
	std::cout << "Print memory direction of firstFruitsPointer[0]: " << &firstFruitReference << std::endl;
	std::cout << "Print memory direction of      fruits[0]: " << &fruits[0]<< std::endl;
	std::cout << "Print memory direction of      fruits[1]: " << &fruits[1]<< std::endl;
	std::cout << "Print memory direction of      fruits[2]: " << &fruits[2]<< std::endl;
	std::cout << "Print memory direction of      fruits[4]: " << &fruits[3]<< std::endl;

	return 0;
	// TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}