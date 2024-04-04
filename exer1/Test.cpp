/* Let´s revisit the Person class you developed during exercises in previous chapters. Take your implementation
   from exer 9-2 and add output() method that writes the details of a person to the standard output console. */

import person;

using namespace std;

int main()
{
	Person person{ "John", "Doe" };
	person.output();
}