// https://leetcode.com/problems/gray-code/description

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
    vector<int> grayCode(int n)
    {
        vector<int> v;
        int p = (1 << n);
        for (int i = 0; i < p; i++)
        {
            v.push_back(i ^ (i / 2));
        }
        return v;
    }
};

int main()
{
    Solution s;
    vector<int> ans = s.grayCode(5);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}