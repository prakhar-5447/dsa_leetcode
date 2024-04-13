// https://leetcode.com/problems/diameter-of-binary-tree/description/

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
    int mD = 0;
    int inorderTraversal(TreeNode *root, int count)
    {
        if (root == NULL)
            return 0;

        int l = inorderTraversal(root->left, count + 1);
        int r = inorderTraversal(root->right, count + 1);
        mD = max(mD, l + r);
        return max(l, r) + 1;
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        int temp = inorderTraversal(root, 0);
        return mD;
    }
};

int main()
{
    TreeNode *t = new TreeNode(2);
    t->left = new TreeNode(1);
    t->right = new TreeNode(3);
    Solution s;
    cout << s.diameterOfBinaryTree(t) << endl;
}