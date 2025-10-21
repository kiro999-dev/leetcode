#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

//my solution O(m * nlog(n))
class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs)
        {
            unordered_map <string,vector<string>> map;
            vector<string>::iterator it;
            string key;
           for (size_t i = 0; i < strs.size(); i++)
           {
                key = strs[i];
                sort(key.begin(),key.end());
                map[key].push_back(strs[i]);
           }
           vector<vector<string>> res;
           for (auto &p : map)
               res.push_back(p.second);
               return res;
        }

    };
//better solution O(n*m)
class Solution2 {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<string, vector<string>> res;
            for (const auto& s : strs) {
                vector<int> count(26, 0);
                for (char c : s) {
                    count[c - 'a']++;
                }
                string key = to_string(count[0]);
                for (int i = 1; i < 26; ++i) {
                    key += ',' + to_string(count[i]);
                }
                res[key].push_back(s);
            }
            vector<vector<string>> result;
            for (const auto& pair : res) {
                result.push_back(pair.second);
            }
            return result;
        }
    };

