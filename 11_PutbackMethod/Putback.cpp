#include <iostream>
#include <format>

int main()
{
	char c;
	std::cin >> c;
	std::cout << std::format("Retrieved {} before putback('e').", c) << std::endl;

	std::cin.putback('e');  // 'e' will be the next character read off the stream.
	std::cin >> c;
	std::cout << std::format("Retrieved {} after putback('e').", c) << std::endl;

	return 0;
}
