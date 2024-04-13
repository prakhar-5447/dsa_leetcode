// https://leetcode.com/problems/kth-largest-element-in-an-array/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int partition(vector<int> &nums, int start, int end)
    {
        int pivot = end;
        end--;
        int i = start - 1, j = start;
        while (j <= end)
        {
            if (nums[j] > nums[pivot])
                swap(nums[j], nums[++i]);
            j++;
        }
        swap(nums[i + 1], nums[pivot]);
        return i + 1;
    }

    int findKthLargest(vector<int> &nums, int k)
    {
        int i = 0, j = nums.size() - 1;
        while (i <= j)
        {
            int p = partition(nums, i, j);
            if (p == k - 1)
                return nums[p];
            else if (p < k - 1)
                i = p + 1;
            else
                j = p - 1;
        }
        return 0;
    }
};

int main()
{
    vector<int> a = {23, 54, 13, 76, 34, 2, 8, 19};
    Solution s;
    cout << s.findKthLargest(a, 2) << endl;
}