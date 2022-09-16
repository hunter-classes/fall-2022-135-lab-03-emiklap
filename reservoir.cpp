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


double get_min_east() {

	std::ifstream fin("Current_Reservoir_Levels.tsv");

	if (fin.fail()) {
		std::cerr << "FIle cannot be opened for readin." << std::endl;
		exit(1);
	}

	std::string junk;
	getline(fin, junk);

	std::string date;
	double eastSt;
	double minStorage = INT_MAX;

	while(fin >> date >> eastSt) {
		fin.ignore(INT_MAX, '\n');
		if (eastSt < minStorage) {
			minStorage = eastSt;
		}
	}
	fin.close();
	std::cout << "minimum stoarge in East basin: " << minStorage << " billion gallons" << std::endl;
	return minStorage;
}

double get_max_east() {

	std::ifstream fin("Current_Reservoir_Levels.tsv");

	if (fin.fail()) {
		std::cerr << "FIle cannot be opened for readin." << std::endl;
		exit(1);
	}

	std::string junk;
	getline(fin, junk);

	std::string date;
	double eastSt;
	double maxStorage = 0;

	while(fin >> date >> eastSt) {
		fin.ignore(INT_MAX, '\n');
		if (eastSt > maxStorage) {
			maxStorage = eastSt;
		}
	}
	fin.close();
	std::cout << "MAXimum stoarge in East basin: " << maxStorage << " billion gallons" << std::endl;
	return maxStorage;
}

std::string compare_basins(std::string input_date) {
	std::ifstream fin("Current_Reservoir_Levels.tsv");

	if (fin.fail()) {
		std::cerr << "FIle cannot be opened for readin." << std::endl;
		exit(1);
	}

	std::string junk;
	getline(fin, junk);

	std::string date, returnString;
	double eastSt, eastEl, westSt, westEl;

	while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
		fin.ignore(INT_MAX, '\n');
		if (date == input_date) {
			if (eastEl > westEl) {
				returnString = "East";
			} else if (westEl > eastEl) {
				returnString = "West";
			} else {
				returnString = "same";
			}
			break;
		}
	}
	fin.close();
	std::cout << input_date << " " << returnString << std::endl;
	return returnString;
}
