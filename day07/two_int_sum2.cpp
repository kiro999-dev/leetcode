#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
using namespace std;
class Solution {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {
            int l = 0;
            vector<int> res(2);
            int r = numbers.size() -1 ;

            while(l <= r)
            {
                if(numbers[l] + numbers[r] > target)
                    r--;
                else if(numbers[l] + numbers[r] < target)
                    l++;
                else
                    break;
            }
            res[0] = l + 1;
            res[1] = r + 1;

            return res;
        }
    };
int main()
{
    vector <int> array ={5,25,75};
    Solution a;
    a.twoSum(array,100);
}