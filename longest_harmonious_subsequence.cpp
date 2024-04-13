// https://leetcode.com/problems/longest-harmonious-subsequence/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int start = 0;
        int ans = 0;
        int maxAns = 0;

        for (int right = 0; right < nums.size(); right++)
        {
            if (nums[right] - nums[start] == 1)
            {
                ans = right - start + 1;
                maxAns = max(maxAns, ans);
            }
            else if (nums[right] - nums[start] > 1)
            {
                while (nums[right] - nums[start] > 1)
                {
                    start++;
                }
            }
        }

        return maxAns;
    }
};

int main()
{
    vector<int> a = {-3, -1, -1, -1, -3, -2};
    Solution s;
    cout << s.findLHS(a) << endl;
}