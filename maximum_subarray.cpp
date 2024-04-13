// https://leetcode.com/problems/maximum-subarray/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int len = nums.size();
        int sum = 0;
        int ans = nums[0];
        int i = 0;

        for (; i < len; i++)
        {
            sum += nums[i];
            ans = max(ans, sum);
            if (sum <= 0)
                sum = 0;
        }
        return ans;
    }
};

int main()
{
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution s;
    cout << s.maxSubArray(arr) << endl;
}