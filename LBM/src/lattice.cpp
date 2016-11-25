/**
 * @file lattice.cpp
 * @brief Implementation of the lattice class.
 * @date 25 Nov. 2016
 * @author Roland Guichard
 */

#include "globalDefinitions.h"

lattice::lattice(int LX, int LY, int LZ):

	/**
	 * @brief Lattice constructor.
	 * @param LX (int) domain dimension in x-coordinate
	 * @param LY (int) domain dimension in y-coordinate
	 * @param LZ (int) domain dimension in z-coordinate
	 * @return none
	 */

	lx(LX), ly(LY), lz(LZ) {
	Q0 = new float[lz*ly*lx];
	Q1 = new float[lz*ly*lx];
	Q2 = new float[lz*ly*lx];
	Q3 = new float[lz*ly*lx];
	Q4 = new float[lz*ly*lx];
	Q5 = new float[lz*ly*lx];
	Q6 = new float[lz*ly*lx];
	Q7 = new float[lz*ly*lx];
	Q8 = new float[lz*ly*lx];
	Q9 = new float[lz*ly*lx];
	Q10 = new float[lz*ly*lx];
	Q11 = new float[lz*ly*lx];
	Q12 = new float[lz*ly*lx];
	Q13 = new float[lz*ly*lx];
	Q14 = new float[lz*ly*lx];
	Q15 = new float[lz*ly*lx];
	Q16 = new float[lz*ly*lx];
	Q17 = new float[lz*ly*lx];
	Q18 = new float[lz*ly*lx];
}

lattice::lattice(int LX, int LY, int LZ, int dump):

	/**
	* @brief Lattice constructor overloaded.
	* @param LX (int) domain dimension in x-coordinate
	* @param LY (int) domain dimension in y-coordinate
	* @param LZ (int) domain dimension in z-coordinate
	* @param dump (int)
	* @return none
	*/

	lx(LX), ly(LY), lz(LZ){
	Q0 = new float[lz*ly*lx];
	Q1 = new float[lz*ly*lx];
	Q2 = new float[lz*ly*lx];
	Q3 = new float[lz*ly*lx];
	Q4 = new float[lz*ly*lx];
	Q5 = new float[lz*ly*lx];
	Q6 = new float[lz*ly*lx];
	Q7 = new float[lz*ly*lx];
	Q8 = new float[lz*ly*lx];
	Q9 = new float[lz*ly*lx];
	Q10 = new float[lz*ly*lx];
	Q11 = new float[lz*ly*lx];
	Q12 = new float[lz*ly*lx];
	Q13 = new float[lz*ly*lx];
	Q14 = new float[lz*ly*lx];
	Q15 = new float[lz*ly*lx];
	Q16 = new float[lz*ly*lx];
	Q17 = new float[lz*ly*lx];
	Q18 = new float[lz*ly*lx];

	//	int FLOATING_array_size=lx*ly*lz*sizeof(FLOATING);
	//		cudaMalloc((void **)&Q0, FLOATING_array_size);
	//		cudaMalloc((void **)&Q1, FLOATING_array_size);
	//		cudaMalloc((void **)&Q2, FLOATING_array_size);
	//		cudaMalloc((void **)&Q3, FLOATING_array_size);
	//		cudaMalloc((void **)&Q4, FLOATING_array_size);
	//		cudaMalloc((void **)&Q5, FLOATING_array_size);
	//		cudaMalloc((void **)&Q6, FLOATING_array_size);
	//		cudaMalloc((void **)&Q7, FLOATING_array_size);
	//		cudaMalloc((void **)&Q8, FLOATING_array_size);
	//		cudaMalloc((void **)&Q9, FLOATING_array_size);
	//		cudaMalloc((void **)&Q10, FLOATING_array_size);
	//		cudaMalloc((void **)&Q11, FLOATING_array_size);
	//		cudaMalloc((void **)&Q12, FLOATING_array_size);
	//		cudaMalloc((void **)&Q13, FLOATING_array_size);
	//		cudaMalloc((void **)&Q14, FLOATING_array_size);
	//		cudaMalloc((void **)&Q15, FLOATING_array_size);
	//		cudaMalloc((void **)&Q16, FLOATING_array_size);
	//		cudaMalloc((void **)&Q17, FLOATING_array_size);
	//		cudaMalloc((void **)&Q18, FLOATING_array_size);
}

lattice::~lattice() {

	/**
	 * @brief Lattice destructor
	 * @return none
	 */

	delete [] Q0;
	delete [] Q1;
	delete [] Q2;
	delete [] Q3;
	delete [] Q4;
	delete [] Q5;
	delete [] Q6;
	delete [] Q7;
	delete [] Q8;
	delete [] Q9;
	delete [] Q10;
	delete [] Q11;
	delete [] Q12;
	delete [] Q13;
	delete [] Q14;
	delete [] Q15;
	delete [] Q16;
	delete [] Q17;
	delete [] Q18;

	printf("host memories deleted!\n");
}
