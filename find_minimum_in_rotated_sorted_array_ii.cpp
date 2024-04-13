// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0, high = n - 1;

        while (low < high)
        {
            if (nums[low] < nums[high])
                return nums[low];
            int mid = low + (high - low) / 2;
            if (nums[low] > nums[mid])
                high = mid;
            else if (nums[mid] > nums[high])
                low = mid + 1;
            else if (nums[high] == nums[high - 1])
                high--;
            else
                low++;
        }
        return nums[low];
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Solution s;
    cout << s.findMin(arr) << endl;
}