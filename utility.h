#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

// functoin to read contents from file
std::vector<int> getIntegersFromFile(std::string filename) {
	std::string line;
	std::vector<int> vect;
	std::ifstream myfile (filename);

	if (myfile.is_open()) {
		while ( getline (myfile,line) ) {
			std::string str = line;
			std::stringstream ss(str);
			int i;
			while (ss >> i) {
			    vect.push_back(i);

			    if (ss.peek() == ',')
			        ss.ignore();
			}// end while
		}// end while
		myfile.close();
	}// end if
	else std::cout << "Unable to open file" << std::endl;
	return vect;
}// end getVectorFromFile

// A utility function to get maximum of two integers
int max(int a, int b) {
    if (a > b) {
        // a is greater than b
        return a;
    }
    else {
        // b is greater than a or equal
        return b;
    }
}
 

