#include "eratostene.h"
#include <algorithm>
#include <cmath>

Eratostene::Eratostene() {
  cache.push_back(_latest = 2);
}

size_t Eratostene::size() {
  return cache.size();
}

bool Eratostene::generate(int n) {
  if (n == 1)
    return true;

  if (_latest < n) {
    for (int i = _latest + (_latest % 2 == 0 ? 1 : 2); i < n; i += 2) {
      _is_prime(i);
    }
  } else {
    return (n % 2 == 0 ? false : std::binary_search(cache.begin(), cache.end(), n));
  }

  return _is_prime(n);
}

size_t Eratostene::upTo(int n) {
  if (_latest < n)
    generate(n);

  return size_t(std::lower_bound(cache.begin(), cache.end(), n) - cache.begin() + 1);
}

int Eratostene::operator[](size_t pos) {
  while (pos > cache.size())
    generate(_latest + 2);

  return cache[pos];
}

bool Eratostene::is_prime(int n) {
  return (n % 2 == 0 ? false : generate(n));
}

bool Eratostene::_is_prime(int n) {
  _latest = n;

  if (n % 2 == 0)
    return false;

  int limit = int(sqrt(n));

  for (int i = 0; cache[i] <= limit; i++) {
    if (n % cache[i] == 0)
      return false;
  }

  cache.push_back(n);
  return true;
}
