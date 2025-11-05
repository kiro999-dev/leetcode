#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
using namespace std;
class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int l = 0;
            int r = nums.size();
            int m = l + (r-l)/2;
            while(l < r)
            {
                m = l + (r-l)/2;
                if(nums[m] == target)
                    return m;
                if(nums[m] > target)
                    r--;
                else if(nums[m] < target)
                    l++;
            }
            return (-1);
        }
    };