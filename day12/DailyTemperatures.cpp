#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
using namespace std;
class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& temperatures)
        {
            
            stack<pair<int,int>> s;
            vector <int> res(temperatures.size());
            for (size_t i = 0; i < temperatures.size(); i++)
            {

                while(!s.empty() && s.top().first < temperatures[i])
                {
                    std::cout<<s.top().second<<'\n';
                    res[s.top().second] = i - s.top().second;
                    s.pop();
                }
                s.push(make_pair(temperatures[i],i));
            }
            return res;
        }
};
int main()
{
    vector<int> a={73,74,75,71,69,72,76,73};
    Solution d;
    d.dailyTemperatures(a);
}