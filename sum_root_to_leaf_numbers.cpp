// https://leetcode.com/problems/sum-root-to-leaf-numbers/description/

#include <bits/stdc++.h>

#define vi vector<int>
#define vii vector<vector<int>>
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define c(a) cout << a << endl

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
    int sumNumbers(TreeNode *root)
    {
        long long int ans = 0, res = 0;
        solve(ans, res, root);
        return res;
    }

    void solve(long long int ans, long long int &res, TreeNode *root)
    {
        if (root == NULL)
            return;

        ans = ans * 10 + root->val;
        if (root->left == NULL & root->right == NULL)
        {
            res += ans;
            return;
        }

        if (root->left != NULL)
            solve(ans, res, root->left);
        if (root->right != NULL)
            solve(ans, res, root->right);
    }
};

int main()
{
    TreeNode *t = new TreeNode(4);
    t->left = new TreeNode(9);
    t->right = new TreeNode(0);
    t->left->left = new TreeNode(5);
    t->left->right = new TreeNode(1);
    Solution s;
    c(s.sumNumbers(t));
}