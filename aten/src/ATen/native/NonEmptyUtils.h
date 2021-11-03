#include <ATen/core/TensorBase.h>
#include <algorithm>
#include <vector>

namespace at { namespace native {

static inline int64_t ensure_nonempty_dim(int64_t dim) {
  return std::max<int64_t>(dim, 1);
}

static inline int64_t ensure_nonempty_size(const TensorBase &t, int64_t dim) {
  return t.dim() == 0 ? 1 : t.size(dim);
}

static inline int64_t ensure_nonempty_stride(const TensorBase &t, int64_t dim) {
  return t.dim() == 0 ? 1 : t.stride(dim);
}

using IdxVec = std::vector<int64_t>;
static inline IdxVec ensure_nonempty_vec(IdxVec vec) {
  if (vec.size() == 0) {
    vec.push_back(1);
  }
  return vec;
}

}}  // namespace at::native
