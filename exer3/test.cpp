/* Develop a class called Database that stores Persons (from exercise 13-2) in an std::vector. Provide an add() method,
   to add a person to the database. Also provide a save() method, accepting the name of a file to wich it saves all
   persons in the database. Any existing contens in the file is removed. Add a load() method, accepting the name of a
   file from wichs the database loads all persons. Provide a clear() method to remove all persons from the database.
   Finally, add a method outputAll() that calls output() on all persons in the database. Make sure your implementation
   works, even if there are spaces in a person´s first or last name. */

import person;
import person_database;
#include <iostream>

using namespace std;

int main()
{
	// Fill a database.
	Database db;
	db.add(Person{ "John", "Doe" });
	db.add(Person{ "Marc", "Gregoire", "Mg" });
	db.add(Person{ "Peter", "Van Weert", "PVW" });

	// Output all persons in the database to standard output.
	cout << "Initial database contents:" << endl;
	db.outputAll(cout);

	// Save the database to a file.
	db.save("person.db");

	// Clear the database.
	db.clear();
	cout << "\nDatabase contents after clearing:" << endl;
	db.outputAll(cout);

	// Load database from file.
	cout << "\nLoading database from file..." << endl;
	db.load("person.db");
	cout << "\nDatabase contents after loading from file:" << endl;
	db.outputAll(cout);
}


