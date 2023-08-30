#include <ctime>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <locale>

int main()
{
	// Boolean values
	bool myBool{ true };
	std::cout << "This is the default: " << myBool << std::endl;
	std::cout << "This should be true: " << std::boolalpha << myBool << std::endl;
	std::cout << "This should be 1: " << std::noboolalpha << myBool << std::endl;

	// Simulate printf-style "%6d" with streams
	int i{ 123 };
	printf("This should be '   123': %6d\n", i);
	std::cout << "This should be '   123': " << std::setw(6) << i << std::endl;

	// Simulate printf-style "%06d" with streams
	printf("This should be '000123': %06d\n", i);
	std::cout << "This should be '000123': " << std::setfill('0') << std::setw(6) << i << std::endl;

	// Fill with *
	std::cout << "This should be '***123': " << std::setfill('*') << std::setw(6) << i << std::endl;
	// Reset fill character
	std::cout << std::setfill(' ');

	// Floating-point values
	double dbl{ 1.452 };
	double dbl2{ 5 };
	std::cout << "This should be ' 5': " << std::setw(2) << std::noshowpoint << dbl2 << std::endl;
	std::cout << "This should be @@1.452: " << std::setw(7) << std::setfill('@') << dbl << std::endl;
	// Reset fill character
	std::cout << std::setfill(' ');

	// Instructs cout to start formatting numbers according to your location.
	// Chapter 21 explains the details of the imbue() call and the locale object.
	std::cout.imbue(std::locale{ "" });

	// Format numbers according to your location
	std::cout << "This is 1234567 formatted according to your location: " << 1234567 << std::endl;

	// Money amount. What exactly an amount of money means depends on your
	// location. For example, in the USA, a money amount of 120000 means 120000
	// dollar cents, which is 1200.00 dollars.
	std::cout << "This should be a money amount of 120000, "
		<< "formatted according to your location: "
		<< std::put_money("120000") << std::endl;

	// Date and time
#if !defined(_MSC_VER)
	time_t t_t{ time(nullptr) };  // Get current system time.
	tm* t{ localtime(&t_t) };     // Convert to local time.
	cout << "This should be the current date and time formatted according to your location: "
		<< put_time(t, "%c") << endl;
#else
	// Visual C++:
	time_t t_t{ time(nullptr) };
	tm t;
	localtime_s(&t, &t_t);
	std::cout << "This should be the current date and time formatted according to your location: "
		<< std::put_time(&t, "%c") << std::endl;
#endif

	// Quoted string
	std::cout << "This should be: \"Quoted string with \\\"embedded quotes\\\".\": "
		<< std::quoted("Quoted string with \"embedded quotes\".") << std::endl;

	// Use setprecision manipulator.
	std::cout << "This should be '1.2346': " << std::setprecision(5) << 1.23456789 << std::endl;

	// Use precision() method
	std::cout.precision(5);
	std::cout << "This should be '1.2346': " << 1.23456789 << std::endl;

	return 0;
}
