#include <iostream>
#include <stdexcept>

int main()
{
	std::cout.exceptions(std::ios::failbit | std::ios::badbit | std::ios::eofbit);
	try {
		std::cout << "Hola Xufo." << std::endl;
	}
	catch (const std::ios_base::failure& ex) {
		std::cerr << "Caught exception: " << ex.what()
			<< ", error code = " << ex.code() << std::endl;
	}

	return 0;
}