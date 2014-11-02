#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    bool isPalindrome(string s) {
      return isPalindrome(s.c_str(), s.size());
    }
    
    bool isPalindrome(const char* s, int length)
    {
      if(length <= 1)
        return true;
      
      if(!('0' <= *s && *s <= '9' || 'a' <= *s && *s <= 'z' || 'A' <= *s && *s <= 'Z'))
        return isPalindrome(s + 1, length - 1);
      if(!('0' <= *(s+length-1) && *(s+length-1) <= '9' || 'a' <= *(s+length-1) && *(s+length-1) <= 'z' || 'A' <= *(s+length-1) && *(s+length-1) <= 'Z'))
        return isPalindrome(s, length - 1);
      if(*s == *(s+length-1) || *s == *(s+length-1)+'a'-'A' || *s == *(s+length-1)+'A'-'a')
        return isPalindrome(s + 1, length - 2);
      else
        return false;
    }
};

int main()
{
  string s = "Aa";
  Solution sl;
  if(sl.isPalindrome(s) == true)
    cout << "pass" << endl;
  else
    cout << "fail" << endl;
  return 0;
}
