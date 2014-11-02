#include <map>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
      map<char, int> matchCount;
      map<char, int> matchMaster;
      int imatchCount = 0;
      
      int rb = 0, re = 0;
      int begin = 0, end = 0;
      
      // prepare
      for(int i = 0; i < T.size(); ++i)
        matchMaster[T[i]] += 1;

      // init begin pos
      for(int i = 0; i < S.size(); ++i)
      {
        if(matchMaster[S[i]] == 0)
          continue;
        begin = i;
        break;
      }
      
      // init end pos
      for(int i = 0; i < S.size(); ++i)
      {
        if(matchMaster[S[i]] == 0)
          continue;
        
        matchCount[S[i]]++;
        if(matchCount[S[i]] <= matchMaster[S[i]])
          imatchCount++;
        
        if(imatchCount == T.size())
        {
          end = i;
          break;
        }
      }
      
      // not match
      if(imatchCount != T.size())
        return "";
      
      rb = begin;
      re = end;

      while(1)
      {
        // move begin to next contained character
        char prechar = S[begin];
        if(matchCount[prechar] > matchMaster[prechar])
        {
          matchCount[prechar]--;
          while(++begin < S.size())
          {
            if(matchMaster[S[begin]] == 0)
              continue;
            break;
          }
          if(end - begin <= re - rb)
          {
            re = end;
            rb = begin;
          }
          continue;
        }
        
        while(++begin < S.size())
        {
          if(matchMaster[S[begin]] == 0)
            continue;
          
          if(matchCount[S[begin]] > matchMaster[S[begin]])       
          {
            matchCount[S[begin]]--;
            continue;
          }
          break;
        }
        
        if(begin == S.size())
          break;
        
        // move end to find prechar
        while(++end < S.size())
        {
          if(S[end] == prechar)
          {
            if(end - begin <= re - rb)
            {
              re = end;
              rb = begin;
            }
            break;
          }
          if(matchCount[S[end]] > 0)
            matchCount[S[end]]++;
        }
        
        if(end >= S.size())
          break;
      }
      
      return S.substr(rb, re - rb + 1);
    }
};

int main()
{
  Solution sl;
  cout << sl.minWindow("abcabdebac", "cda");
  return 0;
}
