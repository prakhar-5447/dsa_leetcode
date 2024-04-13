// https://leetcode.com/problems/first-missing-positive/description/

#include <bits/stdc++.h>
#define vi vector<int>
#define vii vector<vector<int>>
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define c(a) cout << a << endl

using namespace std;

// class Solution
// {
// public:
//     int firstMissingPositive(vector<int> &nums)
//     {
//         unordered_map<int, bool> n(false);
//         int maxVal;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (nums[i] > 0)
//                 n[nums[i]] = true;
//             maxVal = max(maxVal, nums[i]);
//         }

//         for (int i = 1; i <= maxVal; i++)
//         {
//             if (!n[i])
//                 return i;
//         }
//         return maxVal + 1;
//     }
// };

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int i = 0;
        for (i = 0; i < nums.size(); i++)
        {
            while (nums[i] != i + 1 && nums[i] > 0 && nums[i] < nums.size() && nums[i] != nums[nums[i] - 1])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (i = 0; i < nums.size(); i++)
        {
            if (nums[i] != i + 1)
                return i + 1;
        }

        return nums.size() + 1;
    }
};

int main()
{
    vi a = {1, 2, 0};
    Solution s;
    c(s.firstMissingPositive(a));
}