#include <map>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
      item = num;
      sort(num.begin(), num.end());
      doPermute(num, 0, 0);
      return results;
    }
    
    
    vector<vector<int> > results;
    map<string, short> records; 
    map<int, short> itemmask;
    vector<int> item;
    void doPermute(vector<int>& data, int index, int prepos)
    {
      if(index >= data.size())
        return;
      
      for(int i = index > 0 && data[index] == data[index-1] ? prepos + 1 : 0; i < data.size(); ++i)
      {
        if(itemmask[i] == 1)
          continue;

        itemmask[i] = 1;
        item[i] = data[index];
        if(index == data.size() - 1)
        {
          // Find a match, verify whether mask exists or not
          verifyAndRecord(); 
        }
        doPermute(data, index+1, i);
        itemmask[i] = 0;
      }
    }
    
    void verifyAndRecord()
    {
      // Verify
      stringstream sstmp;
      for(int i = 0; i < item.size(); ++i)
        sstmp << item[i] << " ";
      
      if(records[sstmp.str()] == 0)
      {
        results.push_back(item);
        records[sstmp.str()] = 1;
      }
    }
};


int main()
{
  Solution sl;
  vector<int> arg;
  arg.push_back(1);
  arg.push_back(1);
  arg.push_back(0);
  arg.push_back(0);
  arg.push_back(1);
  arg.push_back(-1);
  arg.push_back(1);
  
  vector<vector<int> > re = sl.permuteUnique(arg);

  for(int i = 0; i < re.size(); ++i)
  {
    for(int j = 0; j < re[i].size(); ++j)
    {
      cout << re[i][j] << " ";
    }
    cout << endl;
  }
    
  return 0;
}

