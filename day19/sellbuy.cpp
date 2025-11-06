#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
           int l = 0;
           int r = l+1;
            int maxP = 0;
            int profit = 0;
            while(l < r && r < prices.size())
            {
                if(prices[l] > prices[r])
                {
                    l = r;
                }
                else
                {
                    profit = prices[r] - prices[l];
                    maxP = max(maxP,profit);
                }
                r++;
            }
            return maxP;
        }
};
    int main()
    {
        Solution a;
        vector<int> z={10,8,7,5,2};
        cout<<a.maxProfit(z);
    }