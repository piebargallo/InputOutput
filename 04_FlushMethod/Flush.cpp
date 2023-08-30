#include <iostream>

int main()
{
	std::cout << "abc";
	std::cout.flush();    // abc is written to the console.
	std::cout << "def";
	std::cout << std::endl;    // def is written to the console.

	return 0;
}