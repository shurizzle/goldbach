#ifndef _ERATOSTENE_HXX
#define _ERATOSTENE_HXX

#include <vector>

class Eratostene {
  protected:
    std::vector<int> cache;
    bool generate(int);

  public:
    Eratostene();

    size_t size();
    size_t upTo(int);
    int operator[](size_t);
    bool is_prime(int);

  private:
    bool _is_prime(int);
    int _latest;
};

#endif
