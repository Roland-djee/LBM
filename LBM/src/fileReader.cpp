/**
 * @file fileReader.cpp
 * @brief Implementation of input file readers.
 * @date 25 Nov. 2016
 * @author Roland Guichard
 */

#include "globalDefinitions.h"

void readLBMGeometriesFromFile (int &lx, int &ly, int &lz, int &nbDensities, const string filePathAndName) {

	/**
	 * @brief Reads the input values from the LBMGeometry.inp input file.
	 * @param lx (int) domain dimension in x-coordinate
	 * @param ly (int) domain dimension in y-coordinate
	 * @param lz (int) domain dimension in z-coordinate
	 * @param nbDensities (int) number of densities
	 * @param filePathAndName (const str) path to the input file
	 * @return none
	 */

	vector<string> geometryParameters;
	ifstream configFileReader( filePathAndName.c_str() ); // Why c_str ?
//	ifstream configFileReader( filePathAndName );
	string buffer;

	// Read lines from the file
	if (configFileReader.is_open()){
		while (configFileReader >> buffer) {
			geometryParameters.push_back(buffer);
		}
		cout << "Geometry parameters read from: " << filePathAndName.c_str() << endl;
		lx = atoi(geometryParameters[0].c_str());
		cout << "\t Domain length in x: " << lx << endl;

		ly = atoi(geometryParameters[1].c_str());
		cout << "\t Domain length in y: " << ly << endl;

		lz = atoi(geometryParameters[2].c_str());
		cout << "\t Domain length in z: " << lz << endl;

		nbDensities = atoi(geometryParameters[3].c_str());
		cout << "\t Number of densities on each node: " << nbDensities << endl;

		cout <<"In total: " << geometryParameters.size() << " parameters were read." << endl;
		configFileReader.close();
	}
	else {
		cout << "The file " << filePathAndName << " was not found" << endl;
		cout << "Create a new file in the ./input directory with 3 lines (one number on every line), each corresponding to the respective dimension of x, y and z." << endl;
		// Exit the whole program with an error.
		exit (-1);
	}
}
