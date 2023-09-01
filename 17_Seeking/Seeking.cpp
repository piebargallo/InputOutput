#include <iostream>
#include <fstream>
#include <format>

int main()
{
	std::ofstream fout{ "test.out" };
	if (!fout) {
		std::cerr << "Error opening test.out for writing" << std::endl;
		return 1;
	}

	// 1. Output the string "54321".
	fout << "54321";

	// 2. Verify that the marker is at position 5.
	std::streampos curPos{ fout.tellp() };
	if (curPos == 5) {
		std::cout << "Test passed: Currently at position 5" << std::endl;
	}
	else {
		std::cout << "Test failed: Not at position 5" << std::endl;
	}

	// 3. Move to position 2 in the output stream.
	fout.seekp(2, std::ios_base::beg);

	// 4. Output a 0 in position 2 and close the output stream.
	fout << 0;
	fout.close();

	// 5. Open an input stream on test.out.
	std::ifstream fin{ "test.out" };
	if (!fin) {
		std::cerr << "Error opening test.out for reading" << std::endl;
		return 1;
	}

	// 6. Read the first token as an integer.
	int testVal;
	fin >> testVal;
	if (!fin) {
		std::cerr << "Error reading from file" << std::endl;
		return 1;
	}

	// 7. Confirm that the value is 54021.
	const int expected{ 54021 };
	if (testVal == expected) {
		std::cout << std::format("Test passed: Value is {}", expected) << std::endl;
	}
	else {
		std::cout << std::format("Test failed: Value is not {} (it was {})",
			expected, testVal) << std::endl;
	}
}