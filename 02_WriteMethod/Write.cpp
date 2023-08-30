#include <cstring>
#include <iostream>

int main()
{
	const char* test{ "Hello Xufo\n" };
	std::cout.write(test, strlen(test));

	return 0;
}
