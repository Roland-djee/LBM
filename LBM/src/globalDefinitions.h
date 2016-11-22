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
#include <ctime>

using namespace std;

void readLBMGeometriesFromFile (int &lx, int &ly, int &lz, int &nbDensities, const string filePathAndName);

class lattice {
public:
	float *Q0, *Q1, *Q2, *Q3, *Q4, *Q5, *Q6, *Q7, *Q8, *Q9;
	float *Q10, *Q11, *Q12, *Q13, *Q14, *Q15, *Q16, *Q17, *Q18;
	lattice(int LX, int LY, int LZ);
	lattice(int LX, int LY, int LZ, int dump);
	~lattice();
private:
	int lx, ly, lz;
};

class LBM {

public:
	// Primary Variables
	const int lx, ly, lz;
	const int latticeNodes;
	int noObstacleLatticesAtPenultimateXSlice;
	int threadsForStreamingCollisionAndRelaxation;
	int blocksForStreamingCollisionAndRelaxation;
	int sizeOfAllocatedSharedMemoryForStreamingCollisionAndRelaxation;
	int convectiveBoundaryConditionsBlocks;
	int maxIterations, checkStep;
	float timeElapsed;

//	const string exampleFileName;
	//Methods


	LBM(const int& LX, const int& LY, const int& LZ, const float& DENSITY,
		const float& T0, const float& T1, const float& T2, const float& CSQR);
//	~LBM();

	time_t timeStart, timeEnd;

private:
	// Primary variables
//	int baffle;
//	int threadsPerKernel;
	int timeUnit;
	int twoDimensionalLength;
	int threeDimensionalLength;
	const int floatingSliceSize;
	const int intArraySize;
//	int dataLocation; // 0-CPU, 1-GPU


	float nu, rSmall, reynoldsNb, s, density;
	float prDiff, prOut, prIn, vor;
	const float t0, t1, t2, cSqr, reciprocalCSqr;
	const float tau, omega, oneMinusOmega;

	// Some instantiations
	lattice D3, D3Help;
	lattice D3_d, D3Help_d;

	// Pointers
	int *obstacles;
	int *obstacles_d;

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
	float *tempCPU_vPreviousSpatialBoundary_d;
	float *tempCPU_wPreviousSpatialBoundary_d;

	float *tempCheckDensity_d;
	float *tempCheckDensity_d_full;

	//host memories - for saving the final results
	float *Ux, *Uy, *Uz, *Pressure, *Wx, *Wy, *Wz;

	//Methods
	void createAnExampleConfigurationFile(const string exampleFileName);
	void readExternalConfigurationFileForTheSolver(const string filename);

};

#endif // GLOBALDEFINITIONS_H_
