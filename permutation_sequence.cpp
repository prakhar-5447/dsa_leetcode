// https://leetcode.com/problems/permutation-sequence/description/

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
    string getPermutation(int n, int k)
    {
        int fact = 1;
        vector<int> nums;
        for (int i = 1; i < n; i++)
        {
            fact = fact * i;
            nums.push_back(i);
        }
        nums.push_back(n);
        k = k - 1;
        string ans = "";
        while (true)
        {
            ans = ans + to_string(nums[k / fact]);
            nums.erase(nums.begin() + k / fact);
            if (nums.size() == 0)
            {
                break;
            }
            k = k % fact;
            fact = fact / nums.size();
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.getPermutation(5, 24) << endl;
}