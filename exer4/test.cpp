/* The Database from exercise 13-3 stores all persons in a single file. To practice the filesystem support libary, let´s 
   change that to store each person in its own file. Modify the save() and load() methods to accept a ditrectory as
   argument where files should be stored to or loaded from. The save() method saves every person in the database to its
   own file with the person´s initials as the name and with a .person extension. If a file already exits, overwrite it.
   The load() method iterates over all .person files in a given directory and loads all of then. */

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

	// Save the database to files.
	db.save("F:\\persons");

	// Clear the database.
	db.clear();
	cout << "\nDatabase contents after clearing:" << endl;
	db.outputAll(cout);

	// Load database from files.
	cout << "\nLoading database from files..." << endl;
	db.load("F:\\persons");
	cout << "\nDatabase contents after loading from files:" << endl;
	db.outputAll(cout);
}
