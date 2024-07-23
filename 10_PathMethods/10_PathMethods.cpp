#include <filesystem>
#include <iostream>
using std::cout;
using std::endl;
using namespace std::filesystem;

int main()
{
	path p{ R"(C:\Foo\Bar\file.txt)" };
	cout << p.root_name() << endl;
	cout << p.filename() << endl;
	cout << p.stem() << endl;
	cout << p.extension() << endl;
}