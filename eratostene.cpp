#include "eratostene.h"
#include <algorithm>
#include <cmath>

Eratostene::Eratostene() {
  cache.push_back(_latest = 2);
}

size_t Eratostene::size() {
  return cache.size();
}

size_t Eratostene::upTo(int n) {
  if (_latest < n)
    is_prime(n);

  return size_t(std::lower_bound(cache.begin(), cache.end(), n) - cache.begin() + 1);
}

int Eratostene::operator[](size_t pos) {
  while (pos > cache.size()) {
    is_prime(_latest);
  }

  return cache[pos];
}

bool Eratostene::is_prime(int n) {
  if (n == 1)
    return true;

  if (_latest < n) {
    for (int i = cache.back() + 1; i < n; i++) {
      _is_prime(i);
    }
  } else {
    return std::binary_search(cache.begin(), cache.end(), n);
  }

  return _is_prime(n);
}

bool Eratostene::_is_prime(int n) {
  int limit = int(sqrt(n));

  for (int i = 0; cache[i] <= limit; i++) {
    if (n % cache[i] == 0)
      return false;
  }

  _latest = n;
  cache.push_back(n);
  return true;
}
