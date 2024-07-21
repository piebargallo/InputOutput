// C++ code to demonstrate
// the working of good() function

#include <sstream>
#include <iostream>
using std::stringstream;
using std::cout;
using std::endl;

int main()
{

	// Stream
	stringstream ss;
	ss.clear(ss.eofbit);

	// Using good() function
	bool isGood = ss.good();

	// print result
	cout << "is stream good: "
		<< isGood << endl;

	return 0;
}
