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
	double returnStorage;

	while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
		fin.ignore(INT_MAX, '\n');
		if (date == input_date) {
			std::cout << "East basin storage: " << eastSt << " billion gallons" << std::endl;
			returnStorage = eastSt;
		}
	}
	fin.close();
	return returnStorage;
}
