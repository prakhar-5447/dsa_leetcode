// https://leetcode.com/problems/permutations-ii/description/

#include <bits/stdc++.h>

#define vi vector<int>
#define vii vector<vector<int>>
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define c(a) cout << a << endl

using namespace std;

class Solution
{
private:
    void backTrack(vector<vector<int>> &res, vector<int> &curr, unordered_map<int, int> &m, vector<int> &nums)
    {
        if (curr.size() == nums.size())
        {
            res.push_back(curr);
        }

        for (auto itr = m.begin(); itr != m.end(); itr++)
        {
            if (itr->second == 0)
                continue;
            curr.push_back(itr->first);
            itr->second -= 1;
            backTrack(res, curr, m, nums);
            curr.pop_back();
            itr->second += 1;
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> curr;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }
        backTrack(res, curr, m, nums);
        return res;
    }
};

int main()
{
    vi a = {1, 2, 3};
    Solution s;
    vii ans = s.permuteUnique(a);
    f(i, 0, ans.size())
    {
        f(j, 0, ans[i].size())
        {
            c(ans[i][j]);
        }
        c(" ");
    }
}
