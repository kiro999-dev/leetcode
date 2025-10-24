#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
    public:
        bool isPalindrome(string s) 
        {
            int l = 0;
            int r = s.size()-1;
            while(l!=r && r >=0 && l < s.size())
            {
                cout<<l<<' '<<r<<'\n';
                while(!isalnum(s[l]) && l < s.size())
                    l++;
                while (!isalnum(s[r]) && r >=0)
                    r--;
                if( r >=0 && l < s.size() && (char)tolower(s[l]) != (char)towlower(s[r]))
                {
                    return false;
                }
                l++;
                r--;
            }
            return true;
        }
    };
    
int main()
{
    Solution a;
   std::cout<< a.isPalindrome(".,")<<'\n';
}