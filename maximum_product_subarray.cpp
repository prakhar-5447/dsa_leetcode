// https://leetcode.com/problems/maximum-product-subarray/description/

#include <bits/stdc++.h>

#define vi vector<int>
#define vii vector<vector<int>>
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define c(a) cout << a << endl

using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int maxi = INT_MIN;
        int minCount = 1;
        int maxCount = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            int currMax = maxCount * nums[i];
            int currMin = minCount * nums[i];
            maxCount = max({currMin, nums[i], currMax});
            minCount = min({currMax, nums[i], currMin});
            maxi = max(maxi, maxCount);
        }
        return maxi;
    }
};

int main()
{
    vi a = {3, -2, 4};
    Solution s;
    c(s.maxProduct(a));
}