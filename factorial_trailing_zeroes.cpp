// https://leetcode.com/problems/binary-search-tree-iterator/

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int trailingZeroes(int n)
    {
        int ans = 0;
        while (n > 0)
        {
            ans += n / 5;
            n /= 5;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.trailingZeroes(232) << endl;
}