#include <fstream>
#include <iostream>
#include <string>
#include <climits>

double get_east_storage(std::string input_date) {
	std::ifstream fin("Current_Reservoir_Levels.tsv");

	if (fin.fail()) {
		std::cerr << "FIle cannot be opened for readin." << std::endl;
		exit(1);
	}

	std::string junk;
	getline(fin, junk);

	std::string date;
	double eastSt, eastEl, westSt, westEl;

	while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
		fin.ignore(INT_MAX, '\n');
		if (date == input_date) {
			std::cout << date << " " << eastSt << std::endl;
		}
	}
	fin.close();
	return 0;
}
