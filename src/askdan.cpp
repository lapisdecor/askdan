#include <iostream>
#include <string>
#include <vector>
#include "rapidcsv.h"

int search(std::string package) {
	std::cout << "You searched for " << package << std::endl;

	// TODO Search pakage_files.csv
	rapidcsv::Document doc("package_list.csv");

	//std::vector<std::string> row = doc.GetRow<std::string>(package);
	//std::cout << "Package Found!" << std::endl;

	// Get columns names
	std::cout << "Columns: ";
	for (const auto& col : doc.GetColumnNames()) {
		std::cout << col << " ";
	}
	std::cout << "\n\n";

	// Get firt column
	if (doc.GetRowCount() > 0) {
		bool found = false;
		size_t j = 0; // column
		for (size_t i = 0; i < doc.GetRowCount(); ++i) {
			//std::cout << doc.GetCell<std::string>(j, i) << "\n";
			if (doc.GetCell<std::string>(j,i) == package) {
				std::cout << "Found " << package << "!"  << std::endl;
				found = true;
				break;
			}
		}
		std::cout << "\n";
		if (!found) {
			std::cout << "Package " << package << " not yet on the csv." << std::endl;
		}
	} 
	
	return 0;
}

int main(int argc, char* argv[]) {
	if (argc == 1) {
		std::cout << "Help: type 'askdan package' to search for a package." << std::endl;
	}
	if (argc > 2) {
		std::cout << "Only one argument is allowed at the moment." << std::endl;
	}
	if (argc == 2) {
		// search package in csv
		search((std::string)argv[1]);
	}
	return 0;
}
