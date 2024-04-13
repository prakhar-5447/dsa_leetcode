// https://leetcode.com/problems/next-permutation/description/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int len = nums.size();
        if (len == 1)
            return;

        if (len == 2)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        if (nums[len - 1] > nums[len - 2])
        {
            swap(nums[len - 1], nums[len - 2]);
        }
        else
        {
            int i = len - 2, j;
            for (; i >= 0; i--)
            {
                if (nums[i] < nums[i + 1])
                    break;
            }

            if (i < 0)
            {
                sort(nums.begin(), nums.end());
                return;
            }

            int minVal = INT_MAX;
            int index = len - 1;
            for (j = i + 1; j < len; j++)
            {
                if (nums[j] > nums[i] && nums[j] < minVal)
                {
                    minVal = nums[j];
                    index = j;
                }
            }
            swap(nums[i], nums[index]);
            sort(nums.begin() + i + 1, nums.end());
        }
    }
};

int main()
{
    vector<int> arr = {2, 1, 3};
    Solution s;
    s.nextPermutation(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}