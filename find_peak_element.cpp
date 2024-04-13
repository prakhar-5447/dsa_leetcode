// https://leetcode.com/problems/find-peak-element/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int i;
        for (i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] > nums[i + 1])
                return i;
        }
        return i;
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Solution s;
    cout << s.findPeakElement(arr) << endl;
}