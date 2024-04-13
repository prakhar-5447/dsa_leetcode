// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int len = nums.size();
        if (len < 2)
            return len;

        int lastVal = -101, i = 0, j = 0;

        while (j < len)
        {
            if (nums[j] > lastVal)
            {
                nums[i] = nums[j];
                lastVal = nums[i];
                i++;
            }
            j++;
        }

        return i;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 3, 5};

    int result = sol.removeDuplicates(arr);
    cout << "no of element is : " << result << endl;
}