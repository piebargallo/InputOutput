#include <iostream>
#include <string>

std::string readName(std::istream& stream);

int main()
{
	std::cout << "Type a name followed by Enter followed by Control+D (Control+Z in Windows) and another Enter: ";
	std::string theName{ readName(std::cin) };

	std::cout << "The name is \"" << theName << "\"" << std::endl;
}

std::string readName(std::istream& stream)
{
	std::string name;
	while (stream) { // Or: while (!stream.fail()) {
		int next{ stream.get() };
		if (!stream || next == std::char_traits<char>::eof())
			break;
		name += static_cast<char>(next);// Append character.
	}
	return name;
}


