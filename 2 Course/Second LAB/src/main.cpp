#include "TTrBMatrix.h"
#include "TSqMatrix.h"
#include "TVector.h"

int main()
{
  TSqMatrix<int> mat1(2);
  TSqMatrix<int> mat2(2);
  TSqMatrix<int> mat3(2);
  TVector<float> vec1(2);
  TVector<float> vec2(2);
  TVector<float> vec3(2);
  std::cin >> mat1[0][0];
  std::cin >> mat1[0][1];
  std::cin >> mat1[1][0];
  std::cin >> mat1[1][1];
  std::cin >> mat2[0][0];
  std::cin >> mat2[0][1];
  std::cin >> mat2[1][0];
  std::cin >> mat2[1][1];
  std::cin >> vec1[0];
  std::cin >> vec1[1];
  std::cin >> vec2[0];
  std::cin >> vec2[1];
  mat3 = mat2 + mat1;
  std::cout << mat3[0][0];
  std::cout << mat3[0][1];
  std::cout << mat3[1][0];
  std::cout << mat3[1][1];
  mat3 = mat2 * mat1;
  std::cout << mat3[0][0];
  std::cout << mat3[0][1];
  std::cout << mat3[1][0];
  std::cout << mat3[1][1];
  mat3 = mat2 * 1;
  std::cout << mat3[0][0];
  std::cout << mat3[0][1];
  std::cout << mat3[1][0];
  std::cout << mat3[1][1];
  mat3 = mat2 - mat1;
  std::cout << mat3[0][0];
  std::cout << mat3[0][1];
  std::cout << mat3[1][0];
  std::cout << mat3[1][1];
  vec3 = vec2 + vec1;
  std::cout << vec3[0];
  std::cout << vec3[1];
  vec3 = vec2 * 2;
  std::cout << vec3[0];
  std::cout << vec3[1];
  vec3 = vec2 * vec1;
  std::cout << vec3[0];
  std::cout << vec3[1];
  return 0;
}