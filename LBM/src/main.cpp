//================================================
// Name: LBM.cpp
// Author: Roland Guichard
// Version:
// Copyright: L-GPL
// Description: CUDA Lattice-Boltzmann in C++
//              as a in-depth C++ project.
//              Adapted from Christos Tsotskas's LBM code
//              (itself adapted from a Fortran code by Prof. Djenidi)
// Input: LBM_configuration.txt, LBM_geometry.txt
// Output: geometry, convergence, report, data.
//         Output files start with "LBM_"
// ================================================

// Possible CUDA extensions
#include "globalDefinitions.h"

using namespace std;

int main() {
	//cuda_device_query();
	int lx = 1000, ly = 1000, lz = 1000, nbDensities = 100;
	string fileName = "inputFile.txt";
	void readLBMGeometriesFromFile (int &lx, int &ly, int &lz, int &nbDensities, const string fileName);


}

