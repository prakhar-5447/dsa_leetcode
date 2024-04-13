// https://leetcode.com/problems/max-consecutive-ones/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int ans = 0, temp = 0;
        int len = nums.size();

        for (int i = 0; i < len; i++)
        {
            if (nums[i] == 0 && temp > 0)
            {
                ans = max(ans, temp);
                temp = 0;
            }
            else if (nums[i] == 1)
                temp++;
        }
        ans = max(ans, temp);

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {0, 0, 1, 1, 1, 1, 0, 1, 1};
    cout << s.findMaxConsecutiveOnes(arr) << endl;
}