#include <iostream>
#include <string>
#include <filesystem>
#include <cstdlib>
#include "rapidcsv.h"
#include <string.h>

namespace fs = std::filesystem;

void recommend(int i, rapidcsv::Document doc) {
	int j = 0;
	std::string arr[4] = {".deb", "Snap", "Flatpak", "AppImage"};
	for (int j = 0; j < 4; j++) {
		if (doc.GetCell<std::string>(j + 1, i) == "1") {
			std::cout << arr[j] << " package is available." << std::endl;
		}
	}
	std::cout << "\n";
	std::cout << arr[stoi(doc.GetCell<std::string>(5, i))] << " recommended by Dan." << std::endl;
	std::cout << "\n";
	std::cout << "Disclaimer: this recomendation is made for ubuntu.\n";
	std::cout << "If you don't agree with the recomendation explain us why\nat askdan issues on github.\n";
	std::cout << "https://github.com/lapisdecor/askdan" << std::endl;
	std::cout << "If you are the developer of the software please state\nyour prefered format.\n";
}

int search(std::string package) {
	//std::cout << "You searched for " << package << std::endl;

	// Search pakage_files.csv
	const char* snap_user_data = std::getenv("SNAP_USER_DATA");
	std::string s(snap_user_data != nullptr ? snap_user_data : "");
	//std::cout << "snap_user_data = " << snap_user_data << std::endl;
	if (s.empty()) {
	        std::cerr << "Error: Not running in a Snap environment!\n";
	        return 1;
	}
	std::string path = (std::string) s + "/data/package_list.csv";
	//std::cout << path << std::endl;

	std::string snap = std::getenv("SNAP");

	fs::path src_csv = fs::path(snap) / "usr" / "data" / "package_list.csv";
	fs::path dest_dir = fs::path(snap_user_data) / "data";
	fs::path dest_csv = dest_dir / "package_list.csv";

	if (!fs::exists(dest_csv)) {
		fs::create_directories(dest_dir);
		fs::copy(src_csv, dest_csv);
	}



	rapidcsv::Document doc(path);

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
			std::cout << "Go to https://github.com/lapisdecor/askdan and add a line on package_list.csv" << std::endl;
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
		if ((std::string)argv[1] == "--help") {
			std::cout << "Help: type 'askdan app_name' to search for an application." << std::endl;
		} else {
			// search package in csv
			search((std::string)argv[1]);
		}
	}
	return 0;
}
