#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <stack>
using namespace std;

class Solution {
    public:
        int evalRPN(vector<string>& tokens) {
            stack<int> s;
            int opreated = 0;
            int num1 = 0;
            int num2 = 0;
            if(tokens.size()==1)
                return atoi(tokens[0].c_str());
            for (string str : tokens)
            {
            
                if(str == "+")
                {
                    num1 = s.top();
                    s.pop();
                    num2 = s.top();
                    s.pop();
                    opreated = num1+num2;
                    s.push(opreated);

                   
                }
               else if(str == "*")
                {
                    num1 = s.top();
                    s.pop();
                    num2 = s.top();
                    s.pop();
                    opreated = num1*num2;
                    s.push(opreated);
                    
                }
                else if(str == "/")
                {
                    num1 = s.top();
                    s.pop();
                    num2 = s.top();
                    s.pop();
                    opreated = num2/num1;
                    s.push(opreated);
                    
                }
               else  if(str == "-")
                {
                    num1 = s.top();
                    s.pop();
                    num2 = s.top();
                    s.pop();
                    opreated = num2-num1;
                    s.push(opreated);
                    
                }
                else
                    s.push(atoi(str.c_str()));
            }
           
            return opreated;
        }
};

int main()
{
    Solution a;
    vector<string> x={"9"};

    std::cout<<a.evalRPN(x)<<'\n';
}