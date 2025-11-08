
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int l = 0;
        int n = matrix[0].size() - 1;
        int r = n;
        int m = l + ((r - l) / 2);

        for (vector<int> row : matrix)
        {
            l = 0;
            r = n;
            m = l + ((r - l) / 2);
            while (l < r)
            {
                if (row[m] > target)
                    r--;
                else if (row[m] < target)
                    l++;
                else
                    return true;
                m = l + ((r - l) / 2);
            }
        }
        return false;
    }
};

class Solution2
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int l = 0;
        int r = 0;
        int s_size;
        int max_n = 0;
        unordered_set<char> st;
        while (l <= r && r < s.size())
        {
            if (st.count(s[r]))
            {
                l++;
                s_size = st.size();
                max_n = max(max_n, s_size);
            }
            else
                st.insert(s[r]);
            r++;
        }
    }
};
