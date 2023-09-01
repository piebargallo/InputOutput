#include <iostream>
#include <fstream>
#include <string>
#include <string_view>

// Returns false on error
bool changeNumberForID(std::string_view filename, int id, std::string_view newNumber);

int main()
{
	changeNumberForID("data.txt", 263, "415-555-3333");
}

bool changeNumberForID(std::string_view filename, int id, std::string_view newNumber)
{
	std::fstream ioData{ filename.data() };
	if (!ioData) {
		std::cerr << "Error while opening file " << filename << std::endl;
		return false;
	}

	// Loop until the end of file
	while (ioData) {
		// Read the next ID.
		int idRead;
		ioData >> idRead;
		if (!ioData)
			break;

		// Check to see if the current record is the one being changed.
		if (idRead == id) {
			// Seek the write position to the current read position.
			ioData.seekp(ioData.tellg());
			// Output a space, then the new number.
			ioData << " " << newNumber;
			break;
		}

		// Read the current number to advance the stream.
		std::string number;
		ioData >> number;
	}
	return true;
}