// https://leetcode.com/problems/move-zeroes/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int len = nums.size();
        int window = 0;
        for (int i = 0; window < len; window++)
        {
            if (nums[window] != 0)
            {
                int temp = nums[window];
                nums[window] = nums[i];
                nums[i] = temp;
                i++;
            }
        }
    }
};

int main()
{
    vector<int> a = {0, 0, 1, 2, 5, 7, 9, 0};
    Solution s;
    s.moveZeroes(a);
    vector<int>::iterator it;
    for (it = a.begin(); it < a.end(); it++)
    {
        cout << (*it) << " ";
    }
}