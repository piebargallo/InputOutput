/* put() and write() are raw output methods, put accepts a single character, while write accepts
   a character array. */

#include <cstring>
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	cout.put('a') << endl;

	const char* test{ "hello there\n" };
	cout.write(test, strlen(test));
	
	return 0;
}

