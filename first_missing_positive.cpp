#include <iostream>
using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
      // find the minimum number
      int min = A[0];
      int max = A[0];
      int minPo = 2;
      for(int i = 0; i < n; ++i)
      {
        if(A[i] < min)
          min  = A[i];
        if(A[i] < minPo && A[i] > 0)
          minPo = 1;
        if(A[i] > max)
          max = A[i];
      }
      
      if(minPo != 1)
        return 1;
       
      // Set index in A
      int realvalue;
      for(int i = 0; i < n; ++i)
      {
        if(A[i] < min)
          realvalue = 2*min - A[i] - 1;         
        else
          realvalue = A[i];

        if(realvalue < n + 2 && realvalue > 1 && A[realvalue-2] >= min)
          A[realvalue-2] = 2*min - A[realvalue-2] - 1;
      }
      
      // find the first miss
      for(int i = 0; i < n; ++i)
      {
        if(A[i] >= min)
          return i + 2;
      }
      return max + 1;
    }
};

int main()
{
  int a[] = {3,1,2};
  int a1[] = {3,4,-1,1};

  Solution sl;
  cout << sl.firstMissingPositive(a, 3) << endl;
  cout << sl.firstMissingPositive(a1, 4) << endl;
  return 0;
}
