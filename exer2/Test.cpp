/* The output() method from the previous exercise alwais writes the details of a person to the standard output console.
   Change the output() method to have and output stream as parameter and write the details of a person to than stream.
   Test your new implementation int main() by writing a person to the standard output console, a string stream, and a 
   file. Notice how it´s possible to output a person to all kinds of different targets(output console, string streams,
   files, and so on) with a single method using streams. */

import person;
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

int main()
{
	Person person{ "John", "Doe" };

	// Write person to standard output console.
	person.output(cout);

	// Write person to a string stream.
	ostringstream oss;
	person.output(oss);
	// Verify the contents of the string stream.
	cout << oss.str() << endl;

	// Write person to a file.
	ofstream outFile{ "person.txt" };
	person.output(outFile);
}
