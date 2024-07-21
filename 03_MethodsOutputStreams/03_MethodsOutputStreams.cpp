/* flush() method, most output streams buffer. */
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	cout << "abc";
	cout.flush() << endl;
	return 0;
}