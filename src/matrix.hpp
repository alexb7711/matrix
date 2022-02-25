#ifndef _H_MATRIX_H_
#define _H_MATRIX_H_

// Standard Lib
#include <cstring>
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

    Matrix& operator << (const d_type& val);
    Matrix& operator , (const d_type& val);
    d_type  operator [] (const std::pair<uint,uint> p);

    friend std::ostream &operator << (std::ostream& out, Matrix& m);

    //---------------------------------------------------------------------------
    // Arithmetic
    Matrix& operator + (Matrix& other);
    Matrix& operator - (Matrix& other);

    Matrix& operator * (Matrix& other);
    Matrix& operator * (const d_type val);
    friend Matrix& operator * (const d_type& val, Matrix& m);

    Matrix& operator += (Matrix& other);
    Matrix& operator -= (Matrix& other);
    Matrix& operator *= (Matrix& other);
    Matrix& operator  = (Matrix& other);

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

    //---------------------------------------------------------------------------
    // Memory allocation
    void AllocateMemory();
    void DeallocateMemory();

    //---------------------------------------------------------------------------
    // Input validation
    void IsInitialize();
    bool ValidInput(uint row, uint col);

    //---------------------------------------------------------------------------
    // Arithmetic validation
    bool CheckDimAddition(Matrix& a, Matrix& b);
    bool CheckDimMult();

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
