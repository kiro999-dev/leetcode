#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
using namespace std;

//first try and i got it hell yeah
class Solution
{
public:
    int maxArea(vector<int> &heights)
    {

        int l = 0;
        int r = heights.size() - 1;
        int h = 0;
        int w = 0;
        int max_area = 0;
        while (l < r)
        {
            h = min(heights[l], heights[r]);
            w = r - l;
            max_area = max(h * w, max_area);
            if (heights[l] < heights[r])
                l++;
            else
                r--;
        }
        return max_area;
    }
};
