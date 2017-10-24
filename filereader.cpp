// filereader.cpp
// reading a text file
// eric phung
// tree project - cs362
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

std::vector<int> getVectorFromFile(std::string filename) {
	std::string line;
	std::vector<int> vect;
	ifstream myfile (filename);

	if (myfile.is_open()) {
		while ( getline (myfile,line) ) {
			//cout << line << '\n';
			std::string str = line;
			std::stringstream ss(str);
			int i;

			while (ss >> i) {
			    vect.push_back(i);

			    if (ss.peek() == ',')
			        ss.ignore();
			}// end while
			//for (i=0; i< vect.size(); i++)
				//std::cout << vect.at(i)<<std::endl;

		}// end while
		myfile.close();
		//std::cout << "Found " << vect.size() << " elements in txt file" << std::endl;

	}// end if
	else cout << "Unable to open file" << std::endl;

	return vect;
}// end getVectorFromFile

/*int main () {

	std::vector<int> v; getVectorFromFile("treenode.txt");


	return 0;
}*/