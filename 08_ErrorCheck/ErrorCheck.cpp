#include <iostream>
#include <string>

int main()
{
	std::cout << "Enter numbers on separate lines to add.\n"
		<< "Use Control+D followed by Enter to finish (Control+Z in Windows).\n";
	int sum{ 0 };

	if (!std::cin.good()) {
		std::cerr << "Standard input is in a bad state!" << std::endl;
		return 1;
	}

	while (!std::cin.bad()) {
		int number;
		std::cin >> number;
		if (std::cin.good()) {
			sum += number;
		}
		else if (std::cin.eof()) {
			break; // Reached end of file
		}
		else if (std::cin.fail()) {
			// Failure!
			std::cin.clear(); // Clear the failure state.
			std::string badToken;
			std::cin >> badToken; // Consume the bad input.
			std::cerr << "WARNING: Bad input encountered: " << badToken << std::endl;
		}
	}

	std::cout << "The sum is " << sum << std::endl;

	return 0;
}
