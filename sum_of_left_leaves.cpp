// https://leetcode.com/problems/sum-of-left-leaves/description/

#include <bits/stdc++.h>

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
    int leftLeave(TreeNode *root, bool isLeft)
    {
        int ans = 0;
        if (root->left == NULL && root->right == NULL)
        {
            if (isLeft)
                return root->val;
            else
                return 0;
        }

        if (root->right != NULL)
            ans += leftLeave(root->right, false);
        if (root->left != NULL)
            ans += leftLeave(root->left, true);

        return ans;
    }

    int sumOfLeftLeaves(TreeNode *root)
    {           
        return leftLeave(root, false);
    }
};

int main()
{
    TreeNode *t = new TreeNode(2);
    t->left = new TreeNode(1);
    t->right = new TreeNode(3);
    Solution s;
    cout << s.sumOfLeftLeaves(t) << endl;
}