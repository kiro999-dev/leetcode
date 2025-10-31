#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        vector<int> getSneakyNumbers(vector<int>& nums) {
            unordered_map <int,int> map;
            vector<int> res;
            for (int num:nums)
            {
                if(map.find(num) != map.end())
                {
                    res.push_back(num);
                }
                map[num]=num;
            }
            return res;
        }
    };