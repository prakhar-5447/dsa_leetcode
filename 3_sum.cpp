// https://leetcode.com/problems/3sum/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size() - 1;
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < n; i++)
        {
            int low = i + 1, high = n;
            while (low < high)
            {
                if (nums[i] + nums[low] + nums[high] < 0)
                {
                    low++;
                }
                else if (nums[i] + nums[low] + nums[high] > 0)
                {
                    high--;
                }
                else
                {
                    res.push_back({nums[i], nums[low], nums[high]});
                    int tempIndex1 = low, tempIndex2 = high;
                    while (low < high && nums[low] == nums[tempIndex1])
                        low++;
                    while (low < high && nums[high] == nums[tempIndex2])
                        high--;
                }
            }
            while (i + 1 < n && nums[i] == nums[i + 1])
                i++;
        }
        return res;
    }
};

int main()
{
    vector<int> a = {-1, 0, 1, 2, -1, -4};
    Solution s;
    vector<vector<int>> ans = s.threeSum(a);
    cout << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}