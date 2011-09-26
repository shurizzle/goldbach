#include <iostream>
#include <cstdlib>
#include "goldbach.h"

using namespace std;

int main(int argc, char ** argv) {
  int n;
  if (argc != 2) {
    cerr << "USAGE: " << argv[0] << " <number>" << endl;
    exit(1);
  }

  if ((n = atoi(argv[1])) == 0 || n % 2 != 0 || n < 3) {
    cerr << "'" << argv[1] << "' isn't a valid goldbach number" << endl;
    exit(1);
  }

  vector<int> res = goldbach(n);

  cout << n << " = " << "{ { " << res.front() << ", " << (n - res.front()) << " }";
  for (vector<int>::iterator it = res.begin() + 1; it < res.end(); it++)
    cout << ", { " << *it << ", " << (n - *it) << " }";
  cout << " }" << endl;

  return 0;
}
