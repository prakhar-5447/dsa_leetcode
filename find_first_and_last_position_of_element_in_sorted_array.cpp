// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int start = 0, end = nums.size() - 1;
        if (start == end)
        {
            if (nums[start] == target)
                return {start, end};
            else
                return {-1, -1};
        }

        while (start <= end)
        {
            int mid = end - (end - start) / 2;
            if (nums[mid] == target)
            {
                int i, j;
                if (leftSearch(nums, start, mid, target) == -1)
                    i = mid;
                else
                    i = leftSearch(nums, start, mid, target);
                if (rightSearch(nums, mid, end, target) == -1)
                    j = mid;
                else
                    j = rightSearch(nums, mid, end, target);
                return {i, j};
            }
            else if (nums[mid] < target)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return {-1, -1};
    }

    int leftSearch(vector<int> &nums, int start, int end, int target)
    {
        while (start <= end)
        {
            int mid = end - (end - start) / 2;
            if (nums[mid] < target)
                start = mid + 1;
            else if (nums[mid] == target)
                if (leftSearch(nums, start, mid - 1, target) == -1)
                    return mid;
                else
                    return leftSearch(nums, start, mid - 1, target);
        }
        return -1;
    }

    int rightSearch(vector<int> &nums, int start, int end, int target)
    {
        while (start <= end)
        {
            int mid = end - (end - start) / 2;
            if (nums[mid] > target)
                end = mid - 1;
            else if (nums[mid] == target)
            {
                if (rightSearch(nums, mid + 1, end, target) == -1)
                    return mid;
                else
                    return rightSearch(nums, mid + 1, end, target);
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> a = {3, 3};
    Solution s;

    vector<int> ans = s.searchRange(a, 3);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}