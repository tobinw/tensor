#include "densor.h"
#include <iostream>
const char * boolString(bool b)
{
  return b ? "true" : "false";
}
int main(int argc, char * argv[])
{
  // constructor tests
  tns::Densor0 scalar;
  tns::Densor1 vector(3);
  tns::Densor2 matrix(3,3);
  tns::Densor3 t3(3,3,3);
  tns::Densor4 t4(3,3,3,3);
  // scalar access/assignment tests
  scalar() = 0.0;
  double sclr = scalar();
  std::cout << "scalar() == 0.0 : " << boolString(sclr == 0.0) << std::endl;
  scalar() = 1.0;
  sclr = scalar();
  std::cout << "scalar() == 1.0 : " << boolString(sclr == 1.0) << std::endl;
  // vector access/assignment tests
  for(int ii = 0; ii < 3; ++ii)
    vector(ii) = 1.0;
  for(int ii = 0; ii < 3; ++ii)
    std::cout << "vector(" << ii << ") == 1.0 : " << boolString(vector(ii) == 1.0) << std::endl;
  // matrix access/assignment tests
  for(int ii = 0; ii < 3; ++ii)
    for(int jj = 0; jj < 3; ++jj)
      matrix(ii,jj) = ii == jj ? 1.0 : 0.0;
  for(int ii = 0; ii < 3; ++ii)
    for(int jj = 0; jj < 3; ++jj)
      std::cout << "matrix(" << ii << "," << jj << ") == " << (ii == jj ? "1.0 : " : "0.0 : ") << matrix(ii,jj) << " " << boolString(matrix(ii,jj) == (ii == jj ? 1.0 : 0.0)) << std::endl;
  for(int ii = 0; ii < 3; ++ii)
    for(int jj = 0; jj < 3; ++jj)
      for(int kk = 0; kk < 3; ++kk)
        t3(ii,jj,kk) = ((ii == jj) ? ((jj == kk) ? 1.0 : 0.0) : 0.0);
  for(int ii = 0; ii < 3; ++ii)
    for(int jj = 0; jj < 3; ++jj)
      for(int kk = 0; kk < 3; ++kk)
        std::cout << "tensor3(" << ii << "," << jj << "," << kk << ") == " << ((ii == jj) ? ((jj == kk) ? 1.0 : 0.0) : 0.0) << " " << boolString(t3(ii,jj,kk) == ((ii == jj) ? ((jj == kk) ? 1.0 : 0.0) : 0.0)) << std::endl;
  for(int ii = 0; ii < 3; ++ii)
    for(int jj = 0; jj < 3; ++jj)
      for(int kk = 0; kk < 3; ++kk)
        for(int ll = 0; ll < 3; ++ll)
          t4(ii,jj,kk,ll) = (ii == jj ? (jj == kk ? (kk == ll ? 1.0 : 0.0) : 0.0) : 0.0);
  for(int ii = 0; ii < 3; ++ii)
    for(int jj = 0; jj < 3; ++jj)
      for(int kk = 0; kk < 3; ++kk)
        for(int ll = 0; ll < 3; ++ll)
          std::cout << "tensor4(" << ii << "," << jj << "," << kk << "," << ll << ") == " << (ii == jj ? (jj == kk ? (kk == ll ? 1.0 : 0.0) : 0.0) : 0.0) << " " << boolString(t4(ii,jj,kk,ll) == (ii == jj ? (jj == kk ? (kk == ll ? 1.0 : 0.0) : 0.0) : 0.0)) << std::endl;
}
