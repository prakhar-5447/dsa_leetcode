// https://leetcode.com/problems/search-insert-position/description//

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int l = 0, h = nums.size() - 1;

        while (l <= h)
        {
            int m = l + (h - l) / 2;

            if (nums[m] == target)
                return m;
            if (nums[m] < target)
                l = m + 1;
            else
                h = m - 1;
        }
        return l;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 3, 5};
    int target = 4;

    int result = sol.searchInsert(arr, target);
    cout << "index of element is : " << result << endl;
}