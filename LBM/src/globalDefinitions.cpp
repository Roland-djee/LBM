/**
 * Description: Implementation of the global definitions.
 * Created: 8 Nov. 2016
 * Author: Roland Guichard
 */

#include "globalDefinitions.h"

void readLBMGeometriesFromFile (int &lx, int &ly, int &lz, int &nbDensities, const string fileName) {
	vector<string> geometryParameters;
	ifstream configFile(fileName.c_str());
	string buffer;
	if (configFile.is_open()){
		cout << "In the loop baby";
		while (configFile >> buffer) {
			geometryParameters.push_back(buffer);
		}
	}
	cout << fileName.c_str() <<  "\n";
//	cout << 2;

}
