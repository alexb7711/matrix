#ifndef _H_MATRIX_H_
#define _H_MATRIX_H_

// Standard Lib
#include <iostream>
#include <iterator>
#include <utility>

// Custom Lib
#include "utility.hpp"

class Matrix
{
  public:
    Matrix(uint row, uint col);
    ~Matrix();

    //---------------------------------------------------------------------------
    // I/O
    bool InputByVal(uint r, uint c, d_type val);
    d_type** GetMat();

    void operator << (const d_type& val);
    void operator , (const d_type& val);

    friend std::ostream &operator << (std::ostream& out, Matrix& m);

    //---------------------------------------------------------------------------
    // Arithmetic
    Matrix operator+(Matrix& mat);
    Matrix operator-(Matrix& mat);
    Matrix operator*(Matrix& mat);

    Matrix operator+=(Matrix& mat);
    Matrix operator-=(Matrix& mat);
    Matrix operator*=(Matrix& mat);
    Matrix operator=(Matrix& mat);

    //---------------------------------------------------------------------------
    // Matrix manipulations
    void Transpose();
    void Inverse();

    //---------------------------------------------------------------------------
    // Matrix Info
    std::pair<uint,uint> GetShape();

  private:

//*******************************************************************************
// PRIVATE METHODS
//*******************************************************************************
    void AllocateMemory();
    void DeallocateMemory();
    void IsInitialize();
    bool ValidInput(uint row, uint col);

//*******************************************************************************
// PRIVATE VARS
//*******************************************************************************

    // Current row, column pair that a value will be assigned to next
    std::pair<uint, uint> m_assign;

    // Matrix dimensions
    std::pair<uint, uint> m_shape;

    // Matrix data structure
    d_type** m_mat_vals;
};

#endif
