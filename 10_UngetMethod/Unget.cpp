#include <cctype>
#include <iostream>
#include <string>
#include <format>

void getReservationData()
{
	std::string guestName;
	int partySize{ 0 };
	// Read characters until we find a digit
	char ch;
	std::cin >> std::noskipws;
	while (std::cin >> ch) {
		if (isdigit(ch)) {
			std::cin.unget();
			if (std::cin.fail())
				std::cout << "unget() failed" << std::endl;
			break;
		}
		guestName += ch;
	}
	// Read partysize, if the stream is not in error state
	if (std::cin)
		std::cin >> partySize;
	if (!std::cin) {
		std::cerr << "Error getting party size." << std::endl;
		return;
	}

	std::cout << format("Thank you '{}', party of {}",
		guestName, partySize) << std::endl;
	if (partySize > 10) {
		std::cout << "An extra gratuity will apply." << std::endl;
	}
}

int main()
{
	getReservationData();
}