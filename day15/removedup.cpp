#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            unordered_map <int,int> map;
            vector<int> res;
            for (int num:nums)
            {
                if(map.find(num)!=map.end())
                {
                }
                else
                    res.push_back(num);
                map[num] = num;
            }
            nums = res;
            return map.size();
        }
    };

int main()
{
    vector<int> nums={1,1,2};
    Solution a;
    
    std::cout<<a.removeDuplicates(nums)<<'\n';
}