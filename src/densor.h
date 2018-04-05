#ifndef TNS_DENSOR_H_
#define TNS_DENSOR_H_
#include "tensor.h"
#include <cassert>
#include <cstring>
#include <iostream>
#include <tuple>
#include <type_traits>
namespace tns
{
  template <int ORDER, typename VALUE_TYPE>
    class Densor : public Tensor<ORDER,VALUE_TYPE>
  {
  private:
    std::array<int,ORDER> bounds;
    std::array<int,ORDER> access;
    VALUE_TYPE * values;
  public:
    template <typename ... BOUND, typename std::enable_if<sizeof...(BOUND) == ORDER,int>::type = 0>
      Densor(BOUND ... args)
      : bounds({{ args ... }})
      , values(NULL)
    {
      size_t sz = 1;
      for(int ii = 0; ii < ORDER; ++ii)
        sz *= bounds[ii];
      values = new VALUE_TYPE[sz]();
    }
    ~Densor()
    {
      delete [] values;
    }
    template <typename ... INDICES, typename std::enable_if<sizeof...(INDICES) == ORDER, int>::type = 0>
      VALUE_TYPE & operator()(INDICES ... idx)
    {
      access = {{ idx ... }};
      size_t ix = 0;
      size_t sz = 1;
      for(int ii = ORDER-1; ii >= 0; --ii)
      {
        ix += sz * access[ii];
        sz *= bounds[ii];
      }
      return values[ix];
    }
    template <typename INDICES, typename = std::enable_if_t<std::is_pointer<INDICES>::value> >
      VALUE_TYPE & operator()(INDICES & idx)
    {
      size_t ix = 0;
      size_t sz = 1;
      for(int ii = ORDER-1; ii >= 0; --ii)
      {
        ix += sz * idx[ii];
        sz *= bounds[ii];
      }
      return values[ix];
    }
    size_t bound(size_t idx)
    {
      assert(idx < ORDER);
      return bounds[idx];
    }
  };
  class Indexer
  {
  private:
    size_t order;
    size_t * bounds;
    size_t * index;
  public:
    Indexer(size_t o, size_t * b)
      : order(o)
      , bounds(b)
      , index(new size_t[o])
    {
      for(int ii = 0; ii < order; ++ii)
        index[ii] = 0;
    }
    size_t * operator++()
    {
      for(int ii = order-1; ii >= 0; --ii)
      {
        index[ii]++;
        if(index[ii] < bounds[ii])
          break;
        else
        {
          index[ii] = 0;
          if(ii == 0)
            return NULL;
        }
      }
      return &index[0];
    }
  };
  template <int ORDER, typename VALUE_TYPE, std::enable_if_t<ORDER >= 2>::value>
    Densor<ORDER-2,VALUE_TYPE> contract(Densor<ORDER,VALUE_TYPE> & t, int idx0, int idx1)
  {
    assert(idx0 < ORDER && idx1 < ORDER);
    assert(t.bound(idx0) == t.bound(idx1));
    Densor<ORDER-2,VALUE_TYPE> rslt;
    int idx[ORDER];
    Indexer tindxr(ORDER-2,cbnds);
    size_t * rslt_idx = NULL;
    while((rslt_idx = ++tindxr))
    {
      rxlt(rslt_idx) = VALUE_TYPE(0.0);
      for(int bndx = 0; bndx < t.bound(idx0); ++bndx)
      {
        for(int ii = ORDER-1; ii >= 0; ++ii)
          idx[ii] = ii == idx0 ? bndx : ii == idx1 ? bndx : ii;
        rslt(rslt_idx) += t(&idx[0]);
      }
    }
  }
  typedef Densor<0,double> Densor0;
  typedef Densor<1,double> Densor1;
  typedef Densor<2,double> Densor2;
  typedef Densor<3,double> Densor3;
  typedef Densor<4,double> Densor4;
}
#endif
