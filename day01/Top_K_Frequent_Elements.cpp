#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
// my first solution so bad o(n *k)
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
// my second solution after neetcode vd so good o(n)
class Solution2 {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int, int> freq;
            for (int n : nums)
                freq[n]++;
    
            
            vector<vector<int>> bucket(nums.size() + 1);
            for (auto& p : freq)
                bucket[p.second].push_back(p.first);
    
            vector<int> result;
            for (int i = bucket.size() - 1; i >= 0 && result.size() < k; i--) {
                for (int num : bucket[i]) {
                    result.push_back(num);
                    if (result.size() == k)
                        break;
                }
            }
            return result;
        }
    };

int main()
{
    vector<int> nums = {1, 2, 1, 2, 1, 2, 3, 1, 3, 2};
    vector<int> res;
    Solution2 t;
    res = t.topKFrequent(nums, 2);
    for (int nums : res)
    {
        cout << nums << ",";
    }
    cout << endl;
}