// https://leetcode.com/problems/longest-consecutive-sequence/description/

#include <bits/stdc++.h>

#define vi vector<int>
#define vii vector<vector<int>>
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define c(a) cout << a << endl

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
            
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]] = 1;
        }

        map<int, int>::iterator it;
        int prev = INT_MIN;
        int maxCount = 0;
        int count = 1;
        for (it = mp.begin(); it != mp.end(); it++)
        {
            if (it->first == prev + 1)
                count++;
            else
            {
                maxCount = max(count, maxCount);
                count = 1;
            }
            prev = it->first;
        }

        return max(maxCount, count);
    }
};

int main()
{
    vi a = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    Solution s;
    c(s.longestConsecutive(a));
}