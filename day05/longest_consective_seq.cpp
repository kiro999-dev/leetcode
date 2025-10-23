#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
using namespace std;
// my first solution o(nlog(n)) not bad not good
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int count = 1;
        int max = 1;
        int i = 1;
        while (i < nums.size())
        {

            if (nums[i] - nums[i - 1] == 1)
                count++;
            else if (nums[i] - nums[i - 1] != 0)
            {
                if (max < count)
                    max = count;
                count = 1;
            }
            i++;
        }
        if (max < count)
        {
            max = count;
        }
        return max;
    }
};
//better solution o(n)
class Solution2
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> s(nums.begin(),nums.end());
        int len = 0;
        int max;
       for (int num :s)
       {
            len = 1;
            if(s.find(num-1) == s.end())
            {
                while (s.find(num+len) !=s.end())
                {
                    len++;
                }
            }
            if(max < len)
                max = len;
       }
        return len;
    }
};

int main()
{
    vector<int> nums = {9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6};
    Solution a;
    a.longestConsecutive(nums);
}