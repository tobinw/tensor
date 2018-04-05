#include "densor.h"
int main(int argc, char * argv[])
{
  size_t * idx = NULL;
  size_t vorder = 1;
  size_t vbound = 16;
  tns::Indexer vindxr(vorder,&vbound);
  while((idx = ++vindxr) != NULL)
    std::cout << idx[0] << " ";
  std::cout << std::endl;
  size_t morder = 2;
  size_t mbound[] = {3,3};
  tns::Indexer mindxr(morder,&mbound[0]);
  while((idx = ++mindxr) != NULL)
    std::cout << idx[0] << ", " << idx[1] << std::endl;
  size_t torder = 3;
  size_t tbound[] = {3,3,3};
  tns::Indexer tindxr(torder,&tbound[0]);
  while((idx = ++tindxr) != NULL)
    std::cout << idx[0] << ", " << idx[1] << ", " << idx[2] << std::endl;
  size_t t4order = 4;
  size_t t4bound[] = {3,3,3,3};
  tns::Indexer t4indxr(t4order,&t4bound[0]);
  while((idx = ++t4indxr) != NULL)
    std::cout << idx[0] << ", " << idx[1] << ", " << idx[2] << ", " << idx[3] << std::endl;
}
