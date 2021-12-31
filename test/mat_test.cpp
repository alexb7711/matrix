#include"../src/matrix.hpp"

#include "gtest/gtest.h"

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
TEST(MatrixTest, InputByVal)
{
  // Create 2x2 matrix object
  Matrix m(2,2);

  // Assign matrix values
  m << 1 , 2,
       3 , 4;

  std::pair<uint,uint> idx(0,0);
  EXPECT_EQ(m[idx], 1) << " m[0,0] != 0";

  idx = std::make_pair(0,1);
  EXPECT_EQ(m[idx], 2) << " m[0,0] != 0";

  idx = std::make_pair(1,0);
  EXPECT_EQ(m[idx], 3) << " m[0,0] != 0";

  idx = std::make_pair(1,1);
  EXPECT_EQ(m[idx], 4) << " m[0,0] != 0";

  return;
}

//===============================================================================
// RUN TESTS
int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
