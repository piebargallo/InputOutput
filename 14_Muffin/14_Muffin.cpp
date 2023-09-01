#include <iostream>
#include <sstream>
#include <string>

class Muffin
{
public:
	virtual ~Muffin() = default;

	const std::string& getDescription() const { return m_description; }
	void setDescription(std::string description) { m_description = std::move(description); }

	int getSize() const { return m_size; }
	void setSize(int size) { m_size = size; }

	bool hasChocolateChips() const { return m_hasChocolateChips; }
	void setHasChocolateChips(bool hasChips) { m_hasChocolateChips = hasChips; }

	void output() const
	{
		printf("%s, Size is %d, %s\n", getDescription().data(), getSize(),
			(hasChocolateChips() ? "has chips" : "no chips"));
	}

private:
	std::string m_description;
	int m_size{ 0 };
	bool m_hasChocolateChips{ false };
};


Muffin createMuffin(std::istringstream& inStream);

int main()
{
	std::cout << "First, let's create a muffin in code and output it." << std::endl;

	Muffin myMuffin;
	myMuffin.setDescription("Giant_Blueberry_Muffin");
	myMuffin.setSize(42);
	myMuffin.setHasChocolateChips(false);

	printf("The muffin is ");
	myMuffin.output();
	printf(" -- yummy!\n");


	std::cout << "Now we'll create a muffin from a string stream" << std::endl;

	std::istringstream instream{ "My_Muffin 2 true" };
	Muffin m2{ createMuffin(instream) };
	m2.output();
}

Muffin createMuffin(std::istringstream& stream)
{
	Muffin muffin;
	// Assume data is properly formatted:
	// Description size chips

	std::string description;
	int size;
	bool hasChips;

	// Read all three values. Note that chips is represented
	// by the strings "true" and "false"
	stream >> description >> size >> std::boolalpha >> hasChips;
	if (stream) { // Reading was successful.
		muffin.setSize(size);
		muffin.setDescription(description);
		muffin.setHasChocolateChips(hasChips);
	}

	return muffin;
}
