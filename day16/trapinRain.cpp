#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
class Solution
{
public:
    int trap(vector<int> &height)
    {
       int l = 0;
       int r = height.size()-1;
       int maxlift = height[l];
       int maxright = height[r];
       int res = 0;
       while (l < r)
       {
        if(maxlift < maxright)
        {
            l++;
            maxlift = max(maxlift,height[l]);
            res += maxlift - height[l];
        }
        else 
        {
            r--;
            maxright = max(maxright,height[r]);
            res +=maxright-height[r];
        }
       }
       return res;
    }
};
int main()
{
    vector<int> arr = {0, 2, 0, 3, 1, 0, 1, 3, 2, 1};
    Solution a;
    std::cout << a.trap(arr);
}