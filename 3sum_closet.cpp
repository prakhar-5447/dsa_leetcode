// https://leetcode.com/problems/3sum-closest/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int closestSum = 0, minDiff = INT_MAX;
        sort(nums.begin(), nums.end());
        int n = nums.size() - 1;
        for (int i = 0; i < n; i++)
        {
            int start = i + 1, end = n;
            while (start < end)
            {
                int sum = nums[i] + nums[start] + nums[end];
                if (sum == target)
                    return target;
                else if (sum > target)
                {
                    end--;
                    if (nums[end] == nums[end + 1])
                    {
                        int tempEnd = end;
                        while (start < end && nums[end] == nums[tempEnd])
                            end--;
                    }
                }
                else if (sum < target)
                {
                    start++;
                    if (nums[start] == nums[start - 1])
                    {
                        int tempStart = start;
                        while (start < end && nums[start] == nums[tempStart])
                            start++;
                    }
                }

                if (abs(sum - target) < minDiff)
                {
                    minDiff = abs(sum - target);
                    closestSum = sum;
                }
            }
        }
        return closestSum;
    }
};

int main()
{
    vector<int> a = {-1, 2, 1, -4};
    Solution s;
    cout << s.threeSumClosest(a, 1) << endl;
}