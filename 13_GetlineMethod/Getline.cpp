#include <cstddef>
#include <iostream>
#include <string>

const size_t BufferSize{ 1024 };

int main()
{
	char buffer[BufferSize]{ 0 };
	std::cin.getline(buffer, BufferSize);

	std::cout << "***" << buffer << "***" << std::endl;

	std::string myString;
	std::getline(std::cin, myString);

	std::cout << "***" << myString << "***" << std::endl;
}
