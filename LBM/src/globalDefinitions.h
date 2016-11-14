/**
 * Description: Header for global definitions.
 * Created: 8 Nov. 2016
 * Author: Roland Guichard
 */

// Guard
#ifndef GLOBALDEFINITIONS_H_
#define GLOBALDEFINITIONS_H_

//#include<string>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>

using namespace std;

void readLBMGeometriesFromFile (int &lx, int &ly, int &lz, int &nbDensities, const string filePathAndName);

class lattice {

};

class LBM {
	// Public variables
public:
	const int lx, ly, lz;
	const int latticeNodes;
	int noObstacleLatticesAtPenultimateXSlice;
	int threadsForStreamingCollisionAndRelaxation;
	int blocksForStreamingCollisionAndRelaxation;
	int sizeOfAllocatedSharedMemoryForStreamingCollisionAndRelaxation;
	int convectiveBoundaryConditionsBlocks;
	int maxIterations, checkStep;
	float timeElapsed;

	time_t timeStart, timeEnd;

private:
	const int floatingSliceSize;
	const int intArraySize;
	int baffle;
	int threadsPerKernel;
	int timeUnit;
	int twoDimensionalLength;
	int threeDimensionalLength;

	const float t0, t1, t2, cSqr, reciprocalCSqr;
	const float tau, omega, oneMinusOmega;
	float nu, rSmall, reynoldsNb, s, density;
	float prDiff, prOut, prIn, vor;

	lattice D3, D3Help;

	float *uCurrent;
	float *vCurrent;
	float *wCurrent;

	// uPreviousSpatialBoundary: at boundary - 1 (in x)
	float *uPreviousSpatialBoundary;
	float *vPreviousSpatialBoundary;
	float *wPreviousSpatialBoundary;

	// uPreviousTemporalBoundary: at boundary - 1 (in time)
	float *uPreviousTemporalBoundary;
	float *vPreviousTemporalBoundary;
	float *wPreviousTemporalBoundary;

	float *uCurrent_d;
	float *uCurrentTemp_d;
	float *vCurrent_d;
	float *wCurrent_d;

	// uPreviousSpatialBoundary: at boundary - 1 (in x)
	float *uPreviousSpatialBoundary_d;
	float *vPreviousSpatialBoundary_d;
	float *wPreviousSpatialBoundary_d;

	// uPreviousTemporalBoundary: at boundary - 1 (in time)
	float *uPreviousTemporalBoundary_d;
	float *vPreviousTemporalBoundary_d;
	float *wPreviousTemporalBoundary_d;

	float *tempCPU_uCurrent_d;
	float *tempCPU_vCurrent_d;
	float *tempCPU_wCurrent_d;

	float *tempCPU_uPreviousTemporalBoundary_d;
	float *tempCPU_vPreviousTemporalBoundary_d;
	float *tempCPU_wPreviousTemporalBoundary_d;

	float *tempCPU_uPreviousSpatialBoundary_d;
	float *tempCPU_uPreviousSpatialBoundary_d;
	float *tempCPU_uPreviousSpatialBoundary_d;

	float *tempCheckDensity_d;
	float *tempCheckDensity_d_full;


};

#endif // GLOBALDEFINITIONS_H_
