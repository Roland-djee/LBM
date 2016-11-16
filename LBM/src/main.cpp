/**
 * Name: LBM.cpp
 * Author: Roland Guichard
 * Version:
 * Copyright: L-GPL
 * Description: CUDA/OpenACC Lattice-Boltzmann in C++
 *               as a in-depth C++ project.
 *               Adapted from Christos Tsotskas's LBM code
 *               (itself adapted from a Fortran code by Prof. Djenidi)
 *               Input: LBM_configuration.txt, LBM_geometry.txt
 *               Output: geometry, convergence, report, data.
 *               Output files start with "LBM_"
 */

// Possible CUDA extensions
#include "globalDefinitions.h"

//using namespace std;

int main() {
	//cuda_device_query();
	int lx = 1000, ly = 1000, lz = 1000, nbDensities = 100;

	string filePathAndName = "./input/LBMGeometry.inp";

	readLBMGeometriesFromFile (lx, ly, lz, nbDensities, filePathAndName);

	cout << lx << endl;
	cout << ly << endl;
	cout << lz << endl;
	cout << nbDensities << endl;

	// Instantiate the LBM
	LBM myLBM (lx, ly, lz, 1.0, 1.0/3.0, 1.0/18.0, 1.0/36.0, 1.0/3.0);
	myLBM.createAnExampleConfigurationFile("exampleFielName.txt");
//	LBM myLBM( lx, ly, lz, 1.0,  1.0/3.0 , 1.0/18.0, 1.0/36.0, 1.0/3.0);
//	cout << fileName;


	return 0;
}
