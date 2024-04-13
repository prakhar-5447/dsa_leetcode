// https://leetcode.com/problems/minimum-depth-of-binary-tree/description/

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
    int minDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        if (root->left == NULL && root->right == NULL)
            return 1;

        else
        {
            if (root->left != NULL && root->right != NULL)
                return 1 + min(minDepth(root->left), minDepth(root->right));
            else if (root->right != NULL)
                return 1 + minDepth(root->right);
            else
                return 1 + minDepth(root->left);
        }
    }
};

int main()
{
    TreeNode *t = new TreeNode(2);
    t->left = new TreeNode(1);
    t->right = new TreeNode(3);
    Solution s;
    cout << s.minDepth(t) << endl;
}
