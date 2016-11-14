/**
 * Description: Header for global definitions.
 * Created: 8 Nov. 2016
 * Author: Roland Guichard
 */

// Guard
#ifndef GLOBALDEFINITIONS_H
#define GLOBALDEFINITIONS_H

//#include<string>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>

using namespace std;

void readLBMGeometriesFromFile (int &lx, int &ly, int &lz, int &nbDensities, const string filePathAndName);

class LBM {
	// Public variables
public:
	int blah;
};

#endif
