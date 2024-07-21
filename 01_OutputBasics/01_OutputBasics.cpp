#include <iostream>
#include <string>
#include <format>
using std::cout;
using std::endl;
using std::string;
using std::format;

int main()
{
	int i{ 7 };
	cout << format("The value of i: {}", i) << endl;

	char ch{ 'a' };
	cout << format("The char is: {}", ch) << endl;

	string myString{ "Hello World." };
	cout << format("Saludete: {}", myString) << endl;
	return 0;
}