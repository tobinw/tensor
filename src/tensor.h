#ifndef TNS_TENSOR_H_
#define TNS_TENSOR_H_
#include <vector>
namespace tns
{
  template <int ORDER, typename VALUE_TYPE>
    class Tensor
  {
  public:
    template <typename ... INDICES, class std::enable_if<sizeof...(INDICES) == ORDER, int>::type = 0>
      VALUE_TYPE & operator()(INDICES ... idx);
    size_t bound(size_t idx);
  };
}
#endif
