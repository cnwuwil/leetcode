#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
  map<int, int> cache;
  int numTrees(int n) {
    cache[0] = 1;
    cache[1] = 1;
    cache[2] = 2;
    return calcNum(n);
  }
  
  int calcNum(int n)
  {
    if(cache[n] != 0)
      return cache[n];
    
    int re = 0;
    for(int i = 0; i < n; ++i)
    {
      re += calcNum(i) * calcNum(n-1-i);
    }
    cache[n] = re;
    return re;
  }

};

int main()
{
  Solution sl;
  cout << sl.numTrees(4)<<endl;;
  return 0;
}


