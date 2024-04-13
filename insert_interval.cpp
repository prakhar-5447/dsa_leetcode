// https://leetcode.com/problems/insert-interval/description/

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
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        int minRange = newInterval[0], maxRange = newInterval[1];
        for (int i = 0; i < intervals.size(); i++)
        {
            if ((intervals[i][0] >= minRange && intervals[i][0] <= maxRange) || (minRange >= intervals[i][0] && minRange <= intervals[i][1]))
            {
                maxRange = max(maxRange, intervals[i][1]);
                minRange = min(minRange, intervals[i][0]);
                continue;
            }
            if (intervals[i][1] < minRange)
            {
                res.push_back({intervals[i][0], intervals[i][1]});
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
    vii a = {{1, 3}, {6, 9}};
    vi b = {2, 5};
    Solution s;
    vii ans = s.insert(a, b);
    f(i, 0, ans.size())
    {
        f(j, 0, ans[i].size())
        {
            cout << ans[i][j] << " " << endl;
        }
        cout << endl;
    }
}