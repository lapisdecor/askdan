#include <iostream>
#include <string>
#include <vector>
#include "rapidcsv.h"

void recommend(int i, rapidcsv::Document doc) {
	int j = 0;
	std::string arr[4] = {".deb", "Snap", "Flatpak", "AppImage"};
	for (int j = 0; j < 4; j++) { 
		if (doc.GetCell<std::string>(j + 1, i) == "1") {
			std::cout << arr[j] << " found" << std::endl;
		}
	}
	std::cout << "\n";
	std::cout << arr[stoi(doc.GetCell<std::string>(5, i))] << " recommended by Dan." << std::endl;
	std::cout << "\n";
	std::cout << "Disclaimer: this recomendation is made for ubuntu.\n";
	std::cout << "If you don't agree with the recomendation explain us why at askdan issues on github.\n";
	std::cout << "If you are the developer of the software please state your prefered format.\n";
}

int search(std::string package) {
	//std::cout << "You searched for " << package << std::endl;

	// Search pakage_files.csv
	rapidcsv::Document doc("package_list.csv");

	// Get columns names
	//std::cout << "Columns: ";
	//for (const auto& col : doc.GetColumnNames()) {
	//	std::cout << col << " ";
	//}
	//std::cout << "\n\n";

	// Get firt column
	if (doc.GetRowCount() > 0) {
		bool found = false;
		size_t j = 0; // column
		for (size_t i = 0; i < doc.GetRowCount(); ++i) {
			//std::cout << doc.GetCell<std::string>(j, i) << "\n";
			if (doc.GetCell<std::string>(j,i) == package) {
				//std::cout << "Found " << package << "!"  << std::endl;
				found = true;
				recommend(i, doc);
				break;
			}
		}
		std::cout << "\n";
		if (!found) {
			std::cout << "Application " << package << " not yet on the csv. You can add it." << std::endl;
		}
	} 
	
	return 0;
}

int main(int argc, char* argv[]) {
	if (argc == 1) {
		std::cout << "Help: type 'askdan app_name' to search for an application." << std::endl;
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
