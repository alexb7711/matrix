// Standard Lib

// Class header files
#include "matrix.hpp"

//*******************************************************************************
// PUBLIC 
//*******************************************************************************

//---------------------------------------------------------------------------
// Input:
//
// Output:
//
Matrix::Matrix(uint row, uint col):
  m_assign(0,0),
  m_shape(row,col)
{
  AllocateMemory();
  return;
}

//---------------------------------------------------------------------------
// Input:
//    NONE
//
// Output:
//    NONE
//
Matrix::~Matrix()
{
  DeallocateMemory();
}

//---------------------------------------------------------------------------
// Input:
//    r   : row
//    c   : column
//    val : value
//
// Output:
//    Returns if assignment was successful
//
bool Matrix::InputByVal(uint r, uint c, d_type val)
{
  if (ValidInput(r,c))
  {
    // Check if m_mat_vals has been created
    IsInitialize();

    // Assign Value
    m_mat_vals[r][c] = val;

    return true;
  }
  else
    return false;
}

//---------------------------------------------------------------------------
// Input:
//    NONE
//
// Output:
//    nxm matrix
//
d_type** Matrix::GetMat()
{
  return m_mat_vals;
}

//---------------------------------------------------------------------------
// Input:
//    val: First value to be input to matrix using <</, operators
//
// Output:
//    NONE
//
Matrix& Matrix::operator << (const d_type& val)
{
  m_assign.first = m_assign.second = 0u;

  if (ValidInput(m_assign.first, m_assign.second))
    InputByVal(m_assign.first, m_assign.second, val);

  return *this;
}

//---------------------------------------------------------------------------
// Input:
//    val: Value(s) to be input to matrix using , operator
//
// Output:
//    NONE
//
Matrix& Matrix::operator , (const d_type& val)
{
  if (++m_assign.second < m_shape.second)
    InputByVal(m_assign.first, m_assign.second, val);
  else if (m_assign.second >= m_shape.second &&
           m_assign.first  <  m_shape.first)
  {
    // Start assigning from column zero
    m_assign.second = 0;

    InputByVal(++m_assign.first, m_assign.second, val);
  }

  return *this;
}

//---------------------------------------------------------------------------
// Input:
//    NONE
//
// Output:
//    Matrix dimensions
//
d_type Matrix::operator [] (const std::pair<uint,uint> p)
{
  if (ValidInput(p.first, p.second))
      return m_mat_vals[p.first][p.second];
  else
    return 0;
}

//---------------------------------------------------------------------------
// Input:
//    NONE
//
// Output:
//    Matrix dimensions
//
std::ostream &operator << (std::ostream& out, Matrix& m)
{
  // Get the matrix values
  d_type** mat_vals = m.GetMat();

  // Get matrix shape
  std::pair<uint,uint> shape = m.GetShape();

  for (uint i = 0; i < shape.first; ++i)
  {
    for (uint j = 0; j < shape.second; ++j)
    {
      out << mat_vals[i][j] << " ";
    }

    std::cout << std::endl;
  }

  return out;
}

//---------------------------------------------------------------------------
// Input:
//    other: Other matrix to be added to this
//
// Output:
//    The addition of this and other
//
Matrix& Matrix::operator + (Matrix& other)
{
  if (CheckDimAddition(*this, other))
  {

    for(uint i = 0; i < this->GetShape().first; ++i)
    {
      for(uint j = 0; j < this->GetShape().second; ++j)
      {
        m_idx idx                         = std::make_pair(i,j);
        m_mat_vals[idx.first][idx.second] = m_mat_vals[idx.first][idx.second] + other[idx];
      }
    }
  }

  return *this;
}

//---------------------------------------------------------------------------
// Input:
//    other: Other matrix to be subracted from this
//
// Output:
//    The addition of this and other
//
Matrix& Matrix::operator - (Matrix& other)
{
  return (*this) + -1*other;
}

//---------------------------------------------------------------------------
// Input:
//    NONE
//
// Output:
//    NONE
//
// Matrix operator * (Matrix& mat)
// {}

//---------------------------------------------------------------------------
// Input:
//    val: Scalar value to multiply matrix by
//
// Output:
//    The matrix multiplied by scalar
//
Matrix& Matrix::operator * (const d_type val)
{
  for (uint i = 0; i < m_shape.first; ++i)
    for (uint j = 0; j < m_shape.second; ++j)
      m_mat_vals[i][j] *= val;

  return *this;
}

//---------------------------------------------------------------------------
// Input:
//    val: Scalar value to multiply matrix by
//
// Output:
//    The matrix multiplied by scalar
//
Matrix& operator * (const d_type& val, Matrix& m)
{
  return m*val;
}

//---------------------------------------------------------------------------
// Input:
//    NONE
//
// Output:
//    Matrix dimensions
//
// Matrix operator += (Matrix& mat)
// {}

//---------------------------------------------------------------------------
// Input:
//    NONE
//
// Output:
//    Matrix dimensions
//
// Matrix operator -= (Matrix& mat)
// {}

//---------------------------------------------------------------------------
// Input:
//    NONE
//
// Output:
//    Matrix dimensions
//
// Matrix operator *= (Matrix& mat)
// {}

//---------------------------------------------------------------------------
// Input:
//    other: Matrix to be assigned to this
//
// Output:
//    This matrix
//
Matrix& Matrix::operator = (Matrix& other)
{
  DeallocateMemory();

  // Reshape the matrix
  m_idx m_shape = other.GetShape();

  AllocateMemory();

  // Move values from other to this
  for (uint i = 0; i < m_shape.first; ++i)
    memmove(m_mat_vals[i], other.GetMat()[i], sizeof(*GetMat()[0]));

  return *this;
}

//---------------------------------------------------------------------------
// Input:
//    NONE
//
// Output:
//    Matrix dimensions
//
std::pair<uint,uint> Matrix::GetShape()
{
  return m_shape;
}

//*******************************************************************************
// PRIVATE
//*******************************************************************************

//---------------------------------------------------------------------------
// Input:
//    NONE
//
// Output:
//    Allocated memory for m_mat_vals
//
void Matrix::AllocateMemory()
{
  // Create array of pointers
  m_mat_vals = new float* [m_shape.first];

  // Create rows
  for (uint i = 0; i < m_shape.first; ++i)
    m_mat_vals[i] = new float [m_shape.second];

  return;
}

//---------------------------------------------------------------------------
// Input:
//    NONE
//
// Output:
//    Deallocate memory for m_mat_vals
//
void Matrix::DeallocateMemory()
{
  // Delete array of values
  for (uint i = 0; i < m_shape.first; ++i)
    delete[] m_mat_vals[i];

  // Delete array of pointers
  delete[] m_mat_vals;

  return;
}

//---------------------------------------------------------------------------
// Input:
//    NONE
//
// Output:
//    NONE
//
void Matrix::IsInitialize()
{
  if (m_mat_vals == nullptr)
  {
    AllocateMemory();
  }

  return;
}

//---------------------------------------------------------------------------
// Input:
//    row: row where value will be input
//    col: col where value will be input
//
// Output:
//    True if row/column pair is within the bound of the matrix dimensions,
//    false otherwise
//
bool Matrix::ValidInput(uint row, uint col)
{
  return (row < m_shape.first) && (col < m_shape.second);
}

//---------------------------------------------------------------------------
// Input:
//    a: Matrix a
//    b: Matrix b
//
// Output:
//    Returns true if matrix dimensions are the same, otherwise return false
//
bool Matrix::CheckDimAddition(Matrix& a, Matrix& b)
{
    return a.GetShape().first  == b.GetShape().first &&
           a.GetShape().second == b.GetShape().second;
}

//---------------------------------------------------------------------------
// Input:
//
// Output:
//
bool CheckDimMult()
{
  return true;
}
