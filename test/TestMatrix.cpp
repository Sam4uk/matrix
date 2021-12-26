#include "Matrix.hpp"
#include "gtest/gtest.h"
#ifdef FOR_GOOGLE_TESTS
TEST(Matrix, default) {
  Matrix def_ctor;
  EXPECT_EQ(def_ctor.m_rows, 0) << "Cheking private member m_rows";
  EXPECT_EQ(def_ctor.m_columns, 0) << "Cheking private member m_columns";
  EXPECT_EQ(def_ctor.m_matrix, nullptr) << "Cheking private member m_matrix";
}

TEST(Matrix, ctor_with_parm) {
  Matrix ctor_param(2, 6);
  EXPECT_EQ(ctor_param.m_rows, 2);
  EXPECT_EQ(ctor_param.m_columns, 6);
  EXPECT_NE(ctor_param.m_matrix, nullptr);

  EXPECT_THROW(Matrix ctor_param1(-1, 0), std::out_of_range);
  EXPECT_THROW(Matrix ctor_param2(0, -1), std::out_of_range);
  EXPECT_THROW(Matrix ctor_param3(-1, -1), std::out_of_range);
}

TEST(Matrix, Get_columns) {
  Matrix ctor_param(2, 6);
  EXPECT_EQ(ctor_param.m_columns, ctor_param.GetNumColumns());
}

TEST(Matrix, Get_rows) {
  Matrix ctor_param(2, 6);
  EXPECT_EQ(ctor_param.m_rows, ctor_param.GetNumRows());
}
#endif

TEST(Matrix, Reset) {
  Matrix CheckReset(5, 6);
  EXPECT_EQ(CheckReset.GetNumColumns(), 6);
  CheckReset.Reset(10, 11);
  EXPECT_EQ(CheckReset.GetNumColumns(), 11);
}

TEST(Matrix, At_empty) {
  Matrix at;
  EXPECT_THROW(at.At(0, 0), std::out_of_range);
}

TEST(Matrix, At) {
  Matrix at(6, 8);
  at.At(2, 2) = 30;
  EXPECT_EQ(at.At(2, 2), 30);
}

TEST(Matrix, operatorEQ) {
  Matrix a, b;
  EXPECT_EQ(a == b, true);
  a.Reset(2, 3);
  EXPECT_EQ(a == b, false);
  b.Reset(2, 3);
  EXPECT_EQ(a == b, true);
  b.At(0, 0) = 1;
  EXPECT_EQ(a == b, false);
}

TEST(Matrix, Getcolumns) {
  Matrix ctor_param(2, 6);
  EXPECT_EQ(6, ctor_param.GetNumColumns());
}

TEST(Matrix, Getrows) {
  Matrix ctor_param(2, 6);
  EXPECT_EQ(2, ctor_param.GetNumRows());
}