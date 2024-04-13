// https://leetcode.com/problems/balanced-binary-tree/description/

#include <iostream>

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
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        else
            return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    bool isBalanced(TreeNode *root)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return true;

        if (maxDepth(root->left) - maxDepth(root->right) >= -1 && maxDepth(root->left) - maxDepth(root->right) <= 1)
            return isBalanced(root->left) && isBalanced(root->right);

        return false;
    }
};

int main()
{
    TreeNode *l1 = new TreeNode(1);
    l1->left = new TreeNode(2);
    l1->right = new TreeNode(3);

    Solution s;
    if (s.isBalanced(l1))
        cout << "binary tree is balanced" << endl;
    else
        cout << "binary tree is not balanced" << endl;
}