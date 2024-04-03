#include <iostream>
#include <format>
using std::cout;
using std::cin;
using std::endl;
using std::format;

int main()
{
	int userInput;
	cin >> userInput;
	cout << format("User input was {}", userInput) << endl;
}
