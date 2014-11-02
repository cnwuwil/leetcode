#include <stack>
#include <string>

using namespace std;

class Solution {
  public:
    bool isValid(string s) {
      if(s.size()%2 == 1)
        return false;
      
      stack<char> st;
      for(int i = 0; i < s.size(); ++i)
      {
        char c = s.at(i);
        if(c == ')' || c == ']' || c == '}')
        {
          if(st.empty() == true)
            return false;
          char sc = st.top();
          switch(c)
          {
            case ')':
              if(sc != '(')
                return false;
              break;
            case ']':
              if(sc != '[')
                return false;
              break;
            case '}':
              if(sc != '{')
                return false;
              break;
          }
          st.pop();
          continue;
        }
        st.push(c);
      }
      
      return st.empty();
    }
};
