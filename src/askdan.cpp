#include <iostream>


int main(int argc, char* argv[]) {
	if (argc == 1) {
		std::cout << "Help: type 'askdan package' to search for a package." << std::endl;
	}
	if (argc > 2) {
		std::cout << "Only one argument is allowed at the moment." << std::endl;
	}
	return 0;
}
