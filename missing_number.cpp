// https://leetcode.com/problems/missing-number/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int sum = nums[0], temp = 0, i;
        int len = nums.size();

        for (i = 1; i < len; i++)
        {
            sum += nums[i];
            temp += i;
        }
        temp += i;

        return temp - sum;
    }
};

int main()
{
    vector<int> n = {4, 1, 2, 1, 2};
    Solution s;
    cout << s.missingNumber(n) << endl;
}