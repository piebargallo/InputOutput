#include <iostream>
#include <string>
#include <format>

void getReservationData()
{
	std::string guestName;
	int partySize{ 0 };
	// Read characters until we find a digit
	std::cin >> std::noskipws;
	while (true) {
		// 'peek' at next character
		char ch{ static_cast<char>(std::cin.peek()) };
		if (!std::cin)
			break;
		if (isdigit(ch)) {
			// next character will be a digit, so stop the loop
			break;
		}
		// next character will be a non-digit, so read it
		std::cin >> ch;
		if (!std::cin)
			break;
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
