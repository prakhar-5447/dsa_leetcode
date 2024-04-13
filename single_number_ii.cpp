// https://leetcode.com/problems/single-number-ii/description/

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
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (mp[nums[i]] == 2)
                continue;
            mp[nums[i]]++;
            ans ^= nums[i];
        }
        return ans;
    }
};

// class Solution
// {
// public:
//     int singleNumber(vector<int> &nums)
//     {
//         int result = 0;
//         for (int i = 0; i < 32; i++)
//         {
//             int count = 0;

//             for (int num : nums)
//                 count += ((num >> i) & 1);

//             if (count % 3 != 0)
//                 result |= (1 << i);
//         }

//         return result;
//     }
// };

int main()
{
    vi a = {2, 2, 3, 2};
    Solution s;
    c(s.singleNumber(a));
}