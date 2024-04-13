// https://leetcode.com/problems/minimum-size-subarray-sum/description/

#include <iostream>
#include <vector>
#define vi vector<int>
#define vii vector<vector<int>>
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define c(a) cout << a << endl

using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int i = 0;
        int j = 0;
        int sum = 0;
        int mn = INT_MAX;
        while (j < nums.size())
        {
            sum += nums[j];
            while (sum >= target)
            {
                sum -= nums[i];
                mn = min(j - i + 1, mn);
                i++;
            }
            j++;
        }
        
        if (mn == INT_MAX)
            return 0;

        return mn;
    }
};

int main()
{
    vector<int> arr = {1, 2, 4, 3, 5, 7, 6, 4, 5, 3, 2};
    Solution s;
    c(s.minSubArrayLen(5, arr));
}