/**
 * @file gTestAll.cpp
 * @brief Main for all the unit tests
 * @date 1 Dec 2016
 * @author: RolandGuichard
 */

#include <stdio.h>
#include "gtest.h"

GTEST_API_ int main(int argc, char **argv) {
  printf("Running main() from gTestAll.ccp \n");
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


