#include "Matrix.hpp"

#include <stdexcept>

Matrix::Matrix() : m_rows{0}, m_columns{0}, m_matrix{nullptr} {}

Matrix::Matrix(int num_rows, int num_cols)
    : m_rows{num_rows}, m_columns{num_cols} {
  if (num_cols < 0 or num_rows < 0) throw std::out_of_range("out_of_range");
  _init();
}

void Matrix::Reset(int num_rows, int num_cols) {
  if (num_cols < 0 or num_rows < 0) throw std::out_of_range("out_of_range");
  _free();
  m_rows = num_rows;
  m_columns = num_cols;
  _init();
  for (int rows_index{}; rows_index != m_rows; rows_index++)
    for (int cols_index{}; cols_index != m_columns; cols_index++)
      m_matrix[rows_index][cols_index] = 0;
}

Matrix::MatrixType Matrix::At(int num_rows, int num_cols) const {
  if (num_cols < 0 or num_rows < 0 or !m_rows or !m_columns)
    throw std::out_of_range("out_of_range");
  return m_matrix[num_rows][num_cols];
}

Matrix::MatrixType &Matrix::At(int num_rows, int num_cols) {
  if (num_cols < 0 or num_rows < 0 or !m_rows or !m_columns)
    throw std::out_of_range("out_of_range");
  return m_matrix[num_rows][num_cols];
}

int Matrix::GetNumRows() const { return m_rows; }

int Matrix::GetNumColumns() const { return m_columns; }

Matrix::~Matrix() { _free(); }

bool Matrix::operator==(const Matrix &b) const {
  if (m_columns != b.m_columns) return false;
  if (m_rows != b.m_rows) return false;
  if (m_matrix != nullptr) {
    for (int rows_index{}; rows_index != m_rows; rows_index++)
      for (int cols_index{}; cols_index != m_columns; cols_index++)
        if (At(rows_index, cols_index) != b.At(rows_index, cols_index))
          return false;
  }
  return true;
}

void Matrix::_init() {
  m_matrix = new MatrixType *[m_rows];
  for (int rows_index{}; rows_index != m_rows; rows_index++)
    m_matrix[rows_index] = new MatrixType[m_columns];
}

void Matrix::_free() {
  for (int rows_index{}; rows_index != m_rows; rows_index++)
    delete[] m_matrix[rows_index];
  delete[] m_matrix;
}

std::ostream &operator<<(std::ostream &os, const Matrix &matrix) {
  os << matrix.m_rows << ' ' << matrix.m_columns << ' ' << std::endl;
  for (int rows_index{}; rows_index != matrix.m_rows; rows_index++) {
    for (int cols_index{}; cols_index != matrix.m_columns; cols_index++) {
      os << matrix.m_matrix[rows_index][cols_index];
      if ((cols_index + 1) < matrix.m_columns) os << ' ';
    }
    os << std::endl;
  }
  return os;
}

std::istream &operator>>(std::istream &is, Matrix &matrix) {
  matrix._free();
  is >> matrix.m_rows >> matrix.m_columns;
  matrix._init();
  for (int rows_index{}; rows_index != matrix.m_rows; rows_index++) {
    for (int cols_index{}; cols_index != matrix.m_columns; cols_index++)
      is >> matrix.m_matrix[rows_index][cols_index];
  }
  return is;
}

const Matrix operator+(const Matrix &left, const Matrix &right) {
  if (left.m_columns != right.m_columns || left.m_rows != right.m_rows)
    throw std::invalid_argument("invalid_argument");
  Matrix result(left.m_columns, left.m_rows);
  for (int rows_index{}; rows_index != left.m_rows; rows_index++) {
    for (int cols_index{}; cols_index != left.m_columns; cols_index++)
      result.m_matrix[rows_index][cols_index] =
          left.m_matrix[rows_index][cols_index] +
          right.m_matrix[rows_index][cols_index];
  }
  return Matrix();
}