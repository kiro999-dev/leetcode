#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
//my first solution extra memory :( so bad
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> prefix_p;
        vector<int> res;
        int n = nums.size();
        vector<int> postfix_p(n);
        int p_num = 1;
        for (int num : nums)
        {
            prefix_p.push_back(p_num * num);
            p_num *= num;
        }
      
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
                res.push_back(postfix_p[i+1]);
            else if (i == n - 1)
                res.push_back(prefix_p[i-1]);
            else
            {
                res.push_back(prefix_p[i-1] * postfix_p[i+1]);
            }
        }
        return res;
    }
};

int main()
{
    Solution a;
    vector<int> p = {1, 2, 3, 4};
    a.productExceptSelf(p);
}