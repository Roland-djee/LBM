/**
 * @file testGlobalDefinitions.cpp
 * @brief Unit test for globalDefinitions.h
 * @date 1 Dec 2016
 * @author RolandGuichard
 */


# include "gtest.h"
# include "globalDefinitions.h"

//TEST(IntegerFunctionTest, negative) {
//        EXPECT_EQ(1, factorial(-5));
//        EXPECT_EQ(1, factorial(-1));
//        EXPECT_GT(factorial(-10), 0);
//}

//TEST(IntegerFunctionTest, DISABLED_zero) {
//         EXPECT_EQ(1, factorial(0));
//}

TEST(readLBMGeometriesFromFileTest, positive) {

	/* Declare and initialise domain values */
	int lx { };
	int ly { };
	int lz { };
	int nbDensities { };

	/* Test input file */
	string filePathAndName = "./input/LBMGeometryTest.inp";

	/* Read the LBMGeometryTest.inp file, lx, ly, lz will be updated */
	readLBMGeometriesFromFile (lx, ly, lz, nbDensities, filePathAndName);
    EXPECT_EQ(680, lx);
    EXPECT_EQ(70, ly);
    EXPECT_EQ(80, lz);
    EXPECT_EQ(19, nbDensities);
}

TEST(readExternalConfigurationFileForTheSolver, positive) {

	int maxIterations { };
	int checkStep { };
	float nu { };
	float rSmall { };
	float reynoldsNb { };
	float s { };
	int baffle { };
	int threadsPerKernel{ };
	string caseName { };
	/* Input file */
	string filePathAndName = "./input/LBMConfigurationTest.inp";
	readExternalConfigurationFileForTheSolver(maxIterations, checkStep, nu, rSmall, reynoldsNb, s, baffle, threadsPerKernel, caseName, filePathAndName);
	EXPECT_EQ(4000, maxIterations);
	EXPECT_EQ(2500, checkStep);
	EXPECT_FLOAT_EQ(0.0175, nu);
	EXPECT_EQ(7, rSmall);
	EXPECT_EQ(100, reynoldsNb);
	EXPECT_FLOAT_EQ(24.5, s);
	EXPECT_EQ(59, baffle);
	EXPECT_EQ(128, threadsPerKernel);
	EXPECT_STREQ("datum", caseName.c_str());
}


TEST(LBMInstantiationPublicVariablesTest, positive) {

	/* Declare and arbitrarily initialise domain values */
	int lx { 100 };
	int ly { 200 };
	int lz { 300 };
	int maxIterations { 110 };
	int	checkStep { 210 };
	int	baffle { 310 };
	int	threadsPerKernel { 410 };
	float nu { 1. };
	float rSmall { 2. };
	float reynoldsNb { 3. };
	float s { 4. };
	string	caseName { "testCase" };
	float density { 1.0 };
	float t0      { 1.0/3.0 };
	float t1      { 1.0/18.0 };
	float t2      { 1.0/36.0 };
	float cSqr    { 1.0/3.0 };

	/* Instantiate and run the LBM */
	LBM myLBM (lx, ly, lz, maxIterations, checkStep, nu, rSmall,
				reynoldsNb, s, baffle, threadsPerKernel, caseName,
				density, t0, t1, t2, cSqr);

	/* Check the initialisation of public variables */
	EXPECT_EQ(lx, myLBM.lx);
	EXPECT_EQ(ly, myLBM.ly);
	EXPECT_EQ(lz, myLBM.lz);
	EXPECT_EQ(lx * ly * lz, myLBM.latticeNodes);
	EXPECT_EQ(0, myLBM.noObstacleLatticesAtPenultimateXSlice);
	EXPECT_EQ(512, myLBM.threadsForStreamingCollisionAndRelaxation);
	EXPECT_EQ(32, myLBM.blocksForStreamingCollisionAndRelaxation);
	EXPECT_EQ(48 * 1024, myLBM.sizeOfAllocatedSharedMemoryForStreamingCollisionAndRelaxation);
	EXPECT_EQ(32, myLBM.convectiveBoundaryConditionsBlocks);
	EXPECT_EQ(110, myLBM.maxIterations);
	EXPECT_EQ(210, myLBM.checkStep);
	EXPECT_EQ(310, myLBM.baffle);
	EXPECT_EQ(410, myLBM.threadsPerKernel);
	EXPECT_FLOAT_EQ(1., myLBM.nu);
	EXPECT_FLOAT_EQ(2., myLBM.rSmall);
	EXPECT_FLOAT_EQ(3., myLBM.reynoldsNb);
	EXPECT_FLOAT_EQ(4., myLBM.s);
	EXPECT_STREQ("testCase", caseName.c_str());

}

TEST(LBMInstantiationPrivateVariablesTest, positive) {

	/* Declare and arbitrarily initialise domain values */
	int lx { 100 };
	int ly { 200 };
	int lz { 300 };
	int maxIterations { 110 };
	int	checkStep { 210 };
	int	baffle { 310 };
	int	threadsPerKernel { 410 };
	float nu { 1. };
	float rSmall { 2. };
	float reynoldsNb { 3. };
	float s { 4. };
	string	caseName { "testCase" };
	float density { 1.0 };
	float t0      { 1.0/3.0 };
	float t1      { 1.0/18.0 };
	float t2      { 1.0/36.0 };
	float cSqr    { 1.0/3.0 };

	/* Instantiate and run the LBM */
	LBM myLBM (lx, ly, lz, maxIterations, checkStep, nu, rSmall,
				reynoldsNb, s, baffle, threadsPerKernel, caseName,
				density, t0, t1, t2, cSqr);

	/* Check the initialisation of private variables which have been made public
	 * for the purpose of testing.*/

	myLBM.testInitialisationOfPrivateMembers();



}

