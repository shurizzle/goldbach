#include "goldbach.h"
#include "eratostene.h"

std::vector<int> goldbach(int n) {
  std::vector<int> res;

  if (n < 3 || n % 2 != 0)
    return res;

  Eratostene e;

  for (size_t i = 0; i < e.upTo(int(n / 2)); i++) {
    if (e.is_prime(n - e[i]))
      res.push_back(e[i]);
  }

  return res;
}
