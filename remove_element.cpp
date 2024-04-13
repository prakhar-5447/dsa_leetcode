// https://leetcode.com/problems/remove-element/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int len = nums.size();
        int i = 0, j = len - 1;

        while (j >= i)
        {
            while (i < len && nums[i] != val)
            {
                i++;
            }
            while (j >= 0 && i < len && nums[j] == val)
            {
                j--;
            }
            if (j > i)
            {
                nums[i] = nums[j];
                nums[j] = -1;
                i++;
                j--;
            }
        }

        return j + 1;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {3};
    int target = 3;

    int result = sol.removeElement(arr, target);
    cout << "no of element left : " << result<<endl;
}