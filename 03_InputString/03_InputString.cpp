#include <iostream>
#include <format>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	string userInput;
	cin >> userInput;
	cout << format("User input was {}", userInput) << endl;
}