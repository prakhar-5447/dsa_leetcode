// https://leetcode.com/problems/4sum/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        int n = nums.size() - 1;
        for (int i = 0; i < n - 2; i++)
        {

            for (int j = i + 1; j < n - 1; j++)
            {
                int start = j + 1, end = n;
                while (start < end)
                {
                    long long sum = nums[i] + nums[j];
                    sum += +nums[start];
                    if (nums[end] > target - sum)
                        end--;
                    else if (nums[end] < target - sum)
                        start++;
                    else
                    {
                        ans.insert({nums[i], nums[j], nums[start], nums[end]});
                        int tempIndex1 = start, tempIndex2 = end;
                        while (start < end && nums[start] == nums[tempIndex1])
                            start++;
                        while (start < end && nums[end] == nums[tempIndex2])
                            end--;
                    }
                    while (i + 1 < n && nums[i] == nums[i + 1])
                        i++;
                }
            }
        }
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
};

int main()
{
    vector<int> a = {1, 0, -1, 0, -2, 2};
    Solution s;
    vector<vector<int>> ans = s.fourSum(a, 0);
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