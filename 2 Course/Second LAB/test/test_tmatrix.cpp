#include "TMatrix.h"

#include <gtest.h>

using testing::Types;

template <class T>
class TDynamicMatrixTest : public testing::Test {};
typedef Types<int, double> Implementations;

TYPED_TEST_CASE(TDynamicMatrixTest, Implementations);

TYPED_TEST(TDynamicMatrixTest, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicMatrix<TypeParam> mat(3));
}

TYPED_TEST(TDynamicMatrixTest, can_not_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicMatrix<TypeParam> mat(-1));
}

TYPED_TEST(TDynamicMatrixTest, can_get_size)
{
  TDynamicMatrix<TypeParam> mat(3);

  EXPECT_EQ(3, mat.GetSize());
}