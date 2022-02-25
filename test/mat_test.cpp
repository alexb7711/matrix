#include "../src/matrix.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE MatrixTest
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(matrix_test)

//-------------------------------------------------------------------------------
//
BOOST_AUTO_TEST_CASE(InputByVal)
{
  Matrix m(2,2);
  Matrix other(2,2);

  m << 1 , 2,
       3 , 4;

  other << 1 , 2,
           3 , 4;

  std::pair<uint,uint> idx(0,0);
  BOOST_CHECK_EQUAL(m[idx], 1);

  idx = std::make_pair(0,1);
  BOOST_CHECK_EQUAL(m[idx], 2);

  idx = std::make_pair(1,0);
  BOOST_CHECK_EQUAL(m[idx], 3);

  idx = std::make_pair(1,1);
  BOOST_CHECK_EQUAL(m[idx], 4);

  return;

}

//-------------------------------------------------------------------------------
//
BOOST_AUTO_TEST_CASE(Addition)
{
  Matrix m(2,2);
  Matrix other(2,2);

  m << 1 , 2,
       3 , 4;

  other << 1 , 2,
           3 , 4;

  other = m + other;

  std::pair<uint,uint> idx(0,0);
  BOOST_CHECK_EQUAL(m[idx], 2);

  idx = std::make_pair(0,1);
  BOOST_CHECK_EQUAL(m[idx], 4);

  idx = std::make_pair(1,0);
  BOOST_CHECK_EQUAL(m[idx], 6);

  idx = std::make_pair(1,1);
  BOOST_CHECK_EQUAL(m[idx], 8);

  return;
}

//-------------------------------------------------------------------------------
//
BOOST_AUTO_TEST_CASE(Subtraction)
{
  Matrix m(2,2);
  Matrix other(2,2);

  m << 1 , 2,
       3 , 4;

  other << 1 , 2,
           3 , 4;

  other = m - other;

  std::pair<uint,uint> idx(0,0);
  BOOST_CHECK_EQUAL(m[idx], 0);

  idx = std::make_pair(0,1);
  BOOST_CHECK_EQUAL(m[idx], 0);

  idx = std::make_pair(1,0);
  BOOST_CHECK_EQUAL(m[idx], 0);

  idx = std::make_pair(1,1);
  BOOST_CHECK_EQUAL(m[idx], 0);

  return;
}

//-------------------------------------------------------------------------------
//
BOOST_AUTO_TEST_CASE(ScalarMult)
{
  Matrix m(2,2);
  Matrix other(2,2);

  m << 1 , 2,
       3 , 4;

  other << 1 , 2,
           3 , 4;

  m = m*2;

  std::pair<uint,uint> idx(0,0);
  BOOST_CHECK_EQUAL(m[idx], 2);

  idx = std::make_pair(0,1);
  BOOST_CHECK_EQUAL(m[idx], 4);

  idx = std::make_pair(1,0);
  BOOST_CHECK_EQUAL(m[idx], 6);

  idx = std::make_pair(1,1);
  BOOST_CHECK_EQUAL(m[idx], 8);

  return;
}
BOOST_AUTO_TEST_SUITE_END()
