#include <iostream>
#include <string>
#include "csv.h"

int search(std::string package) {
	std::cout << "You searched for " << package << std::endl;

	// TODO Search pakage_files.csv
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
