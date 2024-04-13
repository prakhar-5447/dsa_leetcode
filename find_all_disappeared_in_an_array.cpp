// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        int len = nums.size();
        vector<bool> check(len + 1, false);
        vector<int> ans;
        for (int i = 0; i < len; i++)
        {
            check[nums[i]] = true;
        }

        for (int i = 1; i <= len; i++)
        {
            if (!check[i])
                ans.push_back(i);
        }

        return ans;
    }
};

int main()
{
    vector<int> a = {4, 3, 2, 7, 8, 2, 3, 1};
    Solution s;
    vector<int> ans = s.findDisappearedNumbers(a);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}