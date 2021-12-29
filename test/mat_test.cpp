#include"../src/matrix.hpp"

#include "gtest/gtest.h"

#include<iostream>

//===============================================================================
// TEST CLASS
class MatrixTest : public ::testing::Test
{
  protected:
    //---------------------------------------------------------------------------
    //
    MatrixTest()
    {}

    //---------------------------------------------------------------------------
    //
    ~MatrixTest() override
    {}

    //---------------------------------------------------------------------------
    //
    void SetUp() override
    {}

    //---------------------------------------------------------------------------
    //
    void TearDown() override
    {}
};

//===============================================================================
// TESTS

//-------------------------------------------------------------------------------
//
TEST_F(MatrixTest, InputByVal)
{
  // Create 2x2 matrix object
  Matrix m(2,2);

  // Assign matrix values
  m << 1;// , 2,
       // 3 , 4;

  m , 2;
  m , 3;
  m , 4;

  std::cout << m;

  return;
}

//===============================================================================
// RUN TESTS
int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
