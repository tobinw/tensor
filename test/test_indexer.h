#include "densor.h"
int main(int * argc, char * argv[])
{
  size_t * idx = NULL;
  int vorder = 1;
  int vbound = 16;
  Indexer vindxr(vorder,&vbound);
  while((idx = vindxr++) != NULL)
    std::cout << idx[0] << " ";
  std::cout << std::endl;
  int morder = 2;
  int mbound[] = {3,3};
  Indexer mindxr(morder,&mbound[0]);
  while((idx = mindxr++) != NULL)
    std::cout << idx[0] << ", " << idx[1] << std::endl;
  int torder = 3;
  int tbound[] = {3,3,3};
  Indexer tindxr(torder,&tbound[0]);
  while((idx = tindxr++) != NULL)
    std::cout << indx[0] << ", " << indx[1] << ", " << indx[2] << std::endl;
  int t4order = 4;
  int t4bound[] = {3,3,3,3};
  Indexer t4indxr(t4order,&t4order[0]);
  while((idx = t4idxr++) != NULL)
    std::cout << idx[0] << ", " << idx[1] << ", " << idx[2] << "," << idx[3] << std::endl;
}
