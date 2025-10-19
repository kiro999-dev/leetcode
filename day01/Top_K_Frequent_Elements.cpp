#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
//my first solution so bad o(m*k)
class Solution {

    public:
        vector<int> topKFrequent(vector<int>& nums, int k)
        {
            unordered_map <int ,int> map;
            int i = 0;
            vector<int> res;
           while (i <  nums.size())
           {
                map[nums[i]]++;
                i++;
           }
           i= 0;
           while (i < k)
           {
            auto maxPair = max_element(map.begin(), map.end(),[](const auto &a, const auto &b) {
                    return a.second < b.second;
                });
                res.push_back(maxPair->first);
                map[maxPair->first] = 0;
                i++;

           }
           
            return res;
        }
    };

