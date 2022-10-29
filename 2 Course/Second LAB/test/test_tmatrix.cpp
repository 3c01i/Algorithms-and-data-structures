#include "TMatrix.h"
#include "TSqMatrix.h"
#include "../src/TMatrix.cpp"
#include "../src/TVector.cpp"
#include "../src/TSqMatrix.cpp"

#include <gtest.h>

using testing::Types;

template <class T>
class TMatrixTest : public testing::Test {};
typedef Types<int, double> Implementations;

TYPED_TEST_CASE(TMatrixTest, Implementations);


TYPED_TEST(TMatrixTest, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<TypeParam> mat(3));
}
TYPED_TEST(TMatrixTest, can_create_sqmatrix_with_positive_length)
{
    ASSERT_NO_THROW(TSqMatrix<TypeParam> mat(3));
}


TYPED_TEST(TMatrixTest, can_not_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<TypeParam> mat(-1));
}
TYPED_TEST(TMatrixTest, can_not_create_sqmatrix_with_negative_length)
{
    ASSERT_ANY_THROW(TSqMatrix<TypeParam> mat(-1));
}


TYPED_TEST(TMatrixTest, can_get_matrix_size)
{
  TMatrix<TypeParam> mat(3);

  EXPECT_EQ(3, mat.GetLength());
}
TYPED_TEST(TMatrixTest, can_get_sqmatrix_size)
{
    TSqMatrix<TypeParam> mat(3);

    EXPECT_EQ(3, mat.GetLength());
}

TYPED_TEST(TMatrixTest, can_compare_matrix_equivalence)
{
  TMatrix<TypeParam> mat1(2);
  TMatrix<TypeParam> mat2(2);
  mat1[0][0] = 0;
  mat1[1][0] = 1;
  mat1[1][1] = 2;
  mat2[0][0] = 0;
  mat2[1][0] = 1;
  mat2[1][1] = 2;
  EXPECT_EQ(mat1 == mat2, true);
}
TYPED_TEST(TMatrixTest, can_compare_sqmatrix_equivalence)
{
    TSqMatrix<TypeParam> mat1(2);
    TSqMatrix<TypeParam> mat2(2);
    mat1[0][0] = 0;
    mat1[1][0] = 1;
    mat1[1][1] = 2;
    mat2[0][0] = 0;
    mat2[1][0] = 1;
    mat2[1][1] = 2;
    EXPECT_EQ(mat1 == mat2, true);
}

TYPED_TEST(TMatrixTest, can_compare_matrix_nonequivalence)
{
  TMatrix<TypeParam> mat1(2);
  TMatrix<TypeParam> mat2(2);
  mat1[0][0] = 0;
  mat1[1][0] = 1;
  mat1[1][1] = 2;
  mat2[0][0] = 1;
  mat2[1][0] = 1;
  mat2[1][1] = 2;
  EXPECT_EQ(mat1 != mat2, true);
}
TYPED_TEST(TMatrixTest, can_compare_sqmatrix_nonequivalence)
{
    TSqMatrix<TypeParam> mat1(2);
    TSqMatrix<TypeParam> mat2(2);
    mat1[0][0] = 0;
    mat1[1][0] = 1;
    mat1[1][1] = 2;
    mat2[0][0] = 1;
    mat2[1][0] = 1;
    mat2[1][1] = 2;
    EXPECT_EQ(mat1 != mat2, true);
}

TYPED_TEST(TMatrixTest, can_not_compare_empty_matrix_equivalence)
{
  TMatrix<TypeParam> mat1;
  TMatrix<TypeParam> mat2;
  ASSERT_ANY_THROW(mat1 == mat2);
}
TYPED_TEST(TMatrixTest, can_not_compare_empty_sqmatrix_equivalence)
{
    TSqMatrix<TypeParam> mat1;
    TSqMatrix<TypeParam> mat2;
    ASSERT_ANY_THROW(mat1 == mat2);
}

TYPED_TEST(TMatrixTest, can_not_compare_empty_matrix_nonequivalence)
{
  TMatrix<TypeParam> mat1;
  TMatrix<TypeParam> mat2;
  ASSERT_ANY_THROW(mat1 != mat2);
}
TYPED_TEST(TMatrixTest, can_not_compare_empty_sqmatrix_nonequivalence)
{
    TSqMatrix<TypeParam> mat1;
    TSqMatrix<TypeParam> mat2;
    ASSERT_ANY_THROW(mat1 != mat2);
}

TYPED_TEST(TMatrixTest, can_sum_matrixes)
{
  TMatrix<TypeParam> mat1(2);
  TMatrix<TypeParam> mat2(2);
  mat1[0][0] = 0;
  mat1[1][0] = 1;
  mat1[1][1] = 2;
  mat2[0][0] = 1;
  mat2[1][0] = 1;
  mat2[1][1] = 2;
  TMatrix<TypeParam> mat3 = mat1 + mat2;
  EXPECT_EQ(mat3[0][0], 1);
  EXPECT_EQ(mat3[1][0], 2);
  EXPECT_EQ(mat3[1][1], 4);
}
TYPED_TEST(TMatrixTest, can_sum_sqmatrixes)
{
    TSqMatrix<TypeParam> mat1(2);
    TSqMatrix<TypeParam> mat2(2);
    mat1[0][0] = 0;
    mat1[1][0] = 1;
    mat1[1][1] = 2;
    mat2[0][0] = 1;
    mat2[1][0] = 1;
    mat2[1][1] = 2;
    TSqMatrix<TypeParam> mat3 = mat1 + mat2;
    EXPECT_EQ(mat3[0][0], 1);
    EXPECT_EQ(mat3[1][0], 2);
    EXPECT_EQ(mat3[1][1], 4);
}

TYPED_TEST(TMatrixTest, can_substract_matrixes)
{
  TMatrix<TypeParam> mat1(2);
  TMatrix<TypeParam> mat2(2);
  mat1[0][0] = 3;
  mat1[1][0] = 2;
  mat1[1][1] = 6;
  mat2[0][0] = 1;
  mat2[1][0] = 1;
  mat2[1][1] = 2;
  TMatrix<TypeParam> mat3 = mat1 - mat2;
  EXPECT_EQ(mat3[0][0], 2);
  EXPECT_EQ(mat3[1][0], 1);
  EXPECT_EQ(mat3[1][1], 4);
}
TYPED_TEST(TMatrixTest, can_substract_sqmatrixes)
{
    TSqMatrix<TypeParam> mat1(2);
    TSqMatrix<TypeParam> mat2(2);
    mat1[0][0] = 3;
    mat1[1][0] = 2;
    mat1[1][1] = 6;
    mat2[0][0] = 1;
    mat2[1][0] = 1;
    mat2[1][1] = 2;
    TSqMatrix<TypeParam> mat3 = mat1 - mat2;
    EXPECT_EQ(mat3[0][0], 2);
    EXPECT_EQ(mat3[1][0], 1);
    EXPECT_EQ(mat3[1][1], 4);
}

TYPED_TEST(TMatrixTest, can_not_sum_empty_matrixes)
{
  TMatrix<TypeParam> mat1;
  TMatrix<TypeParam> mat2;
  ASSERT_ANY_THROW(TMatrix<TypeParam> mat3 = mat1 + mat2);
}
TYPED_TEST(TMatrixTest, can_not_sum_empty_sqmatrixes)
{
    TSqMatrix<TypeParam> mat1;
    TSqMatrix<TypeParam> mat2;
    ASSERT_ANY_THROW(TSqMatrix<TypeParam> mat3 = mat1 + mat2);
}

TYPED_TEST(TMatrixTest, can_not_substract_empty_matrixes)
{
  TMatrix<TypeParam> mat1;
  TMatrix<TypeParam> mat2;
  ASSERT_ANY_THROW(TMatrix<TypeParam> mat3 = mat1 - mat2);
}
TYPED_TEST(TMatrixTest, can_not_substract_empty_sqmatrixes)
{
    TSqMatrix<TypeParam> mat1;
    TSqMatrix<TypeParam> mat2;
    ASSERT_ANY_THROW(TSqMatrix<TypeParam> mat3 = mat1 - mat2);
}

TYPED_TEST(TMatrixTest, can_not_sum_matrixes_differrent_sizes)
{
  TMatrix<TypeParam> mat1(1);
  TMatrix<TypeParam> mat2(2);
  ASSERT_ANY_THROW(TMatrix<TypeParam> mat3 = mat1 + mat2);
}
TYPED_TEST(TMatrixTest, can_not_sum_sqmatrixes_differrent_sizes)
{
    TSqMatrix<TypeParam> mat1(1);
    TSqMatrix<TypeParam> mat2(2);
    ASSERT_ANY_THROW(TSqMatrix<TypeParam> mat3 = mat1 + mat2);
}

TYPED_TEST(TMatrixTest, can_not_substract_matrixes_differrent_sizes)
{
  TMatrix<TypeParam> mat1(1);
  TMatrix<TypeParam> mat2(2);
  ASSERT_ANY_THROW(TMatrix<TypeParam> mat3 = mat1 - mat2);
}
TYPED_TEST(TMatrixTest, can_not_substract_sqmatrixes_differrent_sizes)
{
    TSqMatrix<TypeParam> mat1(1);
    TSqMatrix<TypeParam> mat2(2);
    ASSERT_ANY_THROW(TSqMatrix<TypeParam> mat3 = mat1 - mat2);
}

TYPED_TEST(TMatrixTest, can_mult_matrixes)
{
  TMatrix<TypeParam> mat1(2);
  TMatrix<TypeParam> mat2(2);
  mat1[0][0] = 4;
  mat1[1][0] = 5;
  mat1[1][1] = 6;
  mat2[0][0] = 1;
  mat2[1][0] = 2;
  mat2[1][1] = 3;
  TMatrix<TypeParam> mat3 = mat1 * mat2;
  EXPECT_EQ(mat3[0][0], 4);
  EXPECT_EQ(mat3[1][0], 23);
  EXPECT_EQ(mat3[1][1], 18);
}
TYPED_TEST(TMatrixTest, can_mult_sqmatrixes)
{
    TSqMatrix<TypeParam> mat1(2);
    TSqMatrix<TypeParam> mat2(2);
    mat1[0][0] = 4;
    mat1[1][0] = 5;
    mat1[1][1] = 6;
    mat2[0][0] = 1;
    mat2[1][0] = 2;
    mat2[1][1] = 3;
    TSqMatrix<TypeParam> mat3 = mat1 * mat2;
    EXPECT_EQ(mat3[0][0], 4);
    EXPECT_EQ(mat3[1][0], 23);
    EXPECT_EQ(mat3[1][1], 18);
}

TYPED_TEST(TMatrixTest, can_mult_matrix_on_vector)
{
  TMatrix<TypeParam> mat(2);
  TVector<TypeParam> vec1(2);
  mat[0][0] = 1;
  mat[1][0] = 2;
  mat[1][1] = 3;
  vec1[0] = 1;
  vec1[1] = 2;
  TVector<TypeParam> vec2 = mat * vec1;
  EXPECT_EQ(vec2[0], 5);
  EXPECT_EQ(vec2[1], 6);
}
TYPED_TEST(TMatrixTest, can_mult_sqmatrix_on_vector)
{
    TSqMatrix<TypeParam> mat(2);
    TVector<TypeParam> vec1(2);
    mat[0][0] = 1;
    mat[1][0] = 2;
    mat[1][1] = 3;
    vec1[0] = 1;
    vec1[1] = 2;
    TVector<TypeParam> vec2 = mat * vec1;
    EXPECT_EQ(vec2[0], 5);
    EXPECT_EQ(vec2[1], 6);
}

TYPED_TEST(TMatrixTest, can_mult_matrix_on_scalar)
{
  TMatrix<TypeParam> mat(2);
  mat[0][0] = 1;
  mat[1][0] = 2;
  mat[1][1] = 3;
  TMatrix<TypeParam> res = mat * 2;
  EXPECT_EQ(res[0][0], 2);
  EXPECT_EQ(res[1][0], 4);
  EXPECT_EQ(res[1][1], 6);
}
TYPED_TEST(TMatrixTest, can_mult_sqmatrix_on_scalar)
{
    TSqMatrix<TypeParam> mat(2);
    mat[0][0] = 1;
    mat[1][0] = 2;
    mat[1][1] = 3;
    TSqMatrix<TypeParam> res = mat * 2;
    EXPECT_EQ(res[0][0], 2);
    EXPECT_EQ(res[1][0], 4);
    EXPECT_EQ(res[1][1], 6);
}
