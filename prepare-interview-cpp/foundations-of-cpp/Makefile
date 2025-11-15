all:
	g++ -Wall -Wextra -Werror main.cpp Animal.cpp Dog.cpp -fsanitize=address -Wpedantic -o test
val:
	g++ -Wall -Wextra -Werror main.cpp Animal.cpp Dog.cpp -Wpedantic -o test

clean:
	rm -rf *.o test
