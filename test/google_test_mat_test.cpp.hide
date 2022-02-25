#include"../src/matrix.hpp"

#include "gtest/gtest.h"

//===============================================================================
// TEST CLASS
class MatrixTest : public ::testing::Test
{
  protected:
    //---------------------------------------------------------------------------
    //
    MatrixTest():
      m(2,2),
      other(2,2)
    {}

    //---------------------------------------------------------------------------
    //
    // ~MatrixTest() override
    // {}

    //---------------------------------------------------------------------------
    //
    void SetUp() override
    {
      // Assign matrix values
      m << 1 , 2,
           3 , 4;

    other << 1 , 2,
             3 , 4;

      return;
    }

    //---------------------------------------------------------------------------
    //
    // void TearDown() override
    // {}

    //---------------------------------------------------------------------------
    //
    Matrix m;
    Matrix other;
};

//===============================================================================
// TESTS

//-------------------------------------------------------------------------------
//
TEST_F(MatrixTest, InputByVal)
{
  std::pair<uint,uint> idx(0,0);
  EXPECT_EQ(m[idx], 1) << " m[0,0] != 1";

  idx = std::make_pair(0,1);
  EXPECT_EQ(m[idx], 2) << " m[0,0] != 2";

  idx = std::make_pair(1,0);
  EXPECT_EQ(m[idx], 3) << " m[0,0] != 3";

  idx = std::make_pair(1,1);
  EXPECT_EQ(m[idx], 4) << " m[0,0] != 4";

  return;
}

//-------------------------------------------------------------------------------
//
TEST_F(MatrixTest, Addition)
{
  other = m + other;

  std::pair<uint,uint> idx(0,0);
  EXPECT_EQ(m[idx], 2) << " m[0,0] != 2";

  idx = std::make_pair(0,1);
  EXPECT_EQ(m[idx], 4) << " m[0,0] != 4";

  idx = std::make_pair(1,0);
  EXPECT_EQ(m[idx], 6) << " m[0,0] != 6";

  idx = std::make_pair(1,1);
  EXPECT_EQ(m[idx], 8) << " m[0,0] != 8";

  return;
}

//-------------------------------------------------------------------------------
//
TEST_F(MatrixTest, Subtraction)
{
  other = m - other;

  std::pair<uint,uint> idx(0,0);
  EXPECT_EQ(m[idx], 0) << " m[0,0] != 0";

  idx = std::make_pair(0,1);
  EXPECT_EQ(m[idx], 0) << " m[0,0] != 0";

  idx = std::make_pair(1,0);
  EXPECT_EQ(m[idx], 0) << " m[0,0] != 0";

  idx = std::make_pair(1,1);
  EXPECT_EQ(m[idx], 0) << " m[0,0] != 0";

  return;
}

//-------------------------------------------------------------------------------
//
TEST_F(MatrixTest, ScalarMult)
{
  m = m*2;

  std::pair<uint,uint> idx(0,0);
  EXPECT_EQ(m[idx], 2) << " m[0,0] != 2";

  idx = std::make_pair(0,1);
  EXPECT_EQ(m[idx], 4) << " m[0,0] != 4";

  idx = std::make_pair(1,0);
  EXPECT_EQ(m[idx], 6) << " m[0,0] != 6";

  idx = std::make_pair(1,1);
  EXPECT_EQ(m[idx], 8) << " m[0,0] != 8";

  return;
}

//===============================================================================
// RUN TESTS
int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
