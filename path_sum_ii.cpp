// https://leetcode.com/problems/path-sum-ii/description/

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
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<int> ans;
        vector<vector<int>> res;
        path(root, targetSum, res, ans);
        return res;
    }

    void path(TreeNode *root, int targetSum, vector<vector<int>> &res, vector<int> &ans)
    {
        if (root == NULL)
            return;
        ans.push_back(root->val);
        if (root->left == NULL && root->right == NULL)
        {
            if (targetSum - root->val == 0)
                res.push_back(ans);
            ans.pop_back();
            return;
        }

        path(root->left, targetSum - root->val, res, ans);
        path(root->right, targetSum - root->val, res, ans);
        ans.pop_back();
    }
};

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);
    Solution s;
    vii ans = s.pathSum(root, 22);
    f(i, 0, ans.size())
    {
        f(j, 0, ans[i].size())
        {
            c(ans[i][j]);
        }
        c(' ');
    }
}