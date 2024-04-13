// https://leetcode.com/problems/array-partition/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int arrayPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < nums.size(); i += 2)
        {
            sum += nums[i];
        }
        return sum;
    }
};

int main()
{
    vector<int> a = {6, 2, 6, 5, 1, 2};
    Solution s;
    cout << s.arrayPairSum(a) << endl;
}