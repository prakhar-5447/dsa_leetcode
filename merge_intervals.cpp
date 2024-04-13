// https://leetcode.com/problems/merge-intervals/description/

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
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        int minRange = intervals[0][0], maxRange = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if ((intervals[i][0] >= minRange && intervals[i][0] <= maxRange) || (minRange >= intervals[i][0] && minRange <= intervals[i][1]))
            {
                maxRange = max(maxRange, intervals[i][1]);
                minRange = min(minRange, intervals[i][0]);
            }
            else
            {
                res.push_back({minRange, maxRange});
                minRange = intervals[i][0];
                maxRange = intervals[i][1];
            }
        }
        res.push_back({minRange, maxRange});
        return res;
    }
};

int main()
{
    vii a = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    Solution s;
    vii ans = s.merge(a);
    f(i, 0, ans.size())
    {
        f(j, 0, ans[i].size())
        {
            cout << ans[i][j] << " " << endl;
        }
        cout << endl;
    }
}