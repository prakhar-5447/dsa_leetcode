// https://leetcode.com/problems/subsets-ii/description/

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
    void backTrack(vector<vector<int>> &ans, vector<int> &nums, vector<int> &curr, int index)
    {
        ans.push_back(curr);
        for (int i = index; i < nums.size(); i++)
        {
            if (i != index && nums[i] == nums[i - 1])
                continue;
            curr.push_back(nums[i]);
            backTrack(ans, nums, curr, i + 1);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        backTrack(ans, nums, curr, 0);

        return ans;
    }
};

int main()
{
    vi a = {1, 2, 2};
    Solution s;
    vii ans = s.subsetsWithDup(a);
    f(i, 0, ans.size())
    {
        f(j, 0, ans[i].size())
        {
            c(ans[i][j]);
        }
        c(" ");
    }
}
