#pragma once
#include <istream>
#include <ostream>
#ifdef FOR_GOOGLE_TESTS
#include "gtest/gtest.h"
#endif

class Matrix {
 public:
  typedef int MatrixType;
  Matrix();
  Matrix(int num_rows, int num_cols);
  void Reset(int num_rows, int num_cols);
  MatrixType At(int num_rows, int num_cols) const;
  MatrixType &At(int num_rows, int num_cols);
  int GetNumRows() const;
  int GetNumColumns() const;
  ~Matrix();

  friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix);
  friend std::istream &operator>>(std::istream &is, Matrix &matrix);
  friend const Matrix operator+(const Matrix &left, const Matrix &right);
  bool operator==(const Matrix &matrix) const;

 private:
#ifdef FOR_GOOGLE_TESTS
  FRIEND_TEST(Matrix, default);
  FRIEND_TEST(Matrix, ctor_with_parm);
  FRIEND_TEST(Matrix, Get_columns);
  FRIEND_TEST(Matrix, Get_rows);
#endif
  int m_rows;
  int m_columns;
  MatrixType **m_matrix;
  void _init();
  void _free();
};