#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
    public:
        int carFleet(int target, vector<int>& position, vector<int>& speed) {
          vector <pair<int,int>> pair;
          for (size_t i = 0; i < position.size(); i++)
          {
            pair.push_back({position[i],speed[i]});
          }
          sort(pair.rbegin(),pair.rend());
          vector<double> stack;
          for (auto &p : pair)
          {
            stack.push_back(((double)target - p.first ) / p.second);
            if(stack.size() >= 2 && stack.back() <= stack[stack.size() - 2])
            {
                stack.pop_back();
            }
          }
          return stack.size();
        }
    };
    
