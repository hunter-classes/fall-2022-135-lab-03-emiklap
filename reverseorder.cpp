#include <fstream>
#include <iostream>
#include <string>
#include <climits>

void reverse_order(std::string date1, std::string date2) {
    std::ifstream fin("Current_Reservoir_Levels.tsv");

	if (fin.fail()) {
		std::cerr << "FIle cannot be opened for readin." << std::endl;
		exit(1);
	}

	std::string junk;
	getline(fin, junk);

	std::string date;
	double eastSt, eastEl, westSt, westEl;
    int index = 0;
    std::string dates_array[365];
    double elevations_array[365];

    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
		fin.ignore(INT_MAX, '\n');
		if (date1 <= date && date2 >= date) {
            dates_array[index] = date;
            elevations_array[index] = westEl;
            index++;
        }
	}

	for (int i = index - 1; i >= 0; i--) {
        std::cout << dates_array[i] << " " << elevations_array[i] << " ft" << std::endl;
    }
}
