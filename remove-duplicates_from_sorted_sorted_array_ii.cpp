// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int len = nums.size();
        int count = 0;
        if (len < 2)
            return len;

        int lastVal = -10001, i = 0, j = 0;

        while (j < len)
        {
            if (nums[j] == lastVal)
                count++;
            else
                count = 0;
            if (count < 2)
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
    vector<int> arr = {1, 1, 1, 2, 2, 2, 3, 3, 5};
    int result = sol.removeDuplicates(arr);
    cout << "no of element is : " << result << endl;
}