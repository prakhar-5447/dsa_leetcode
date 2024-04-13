// https://leetcode.com/problems/validate-binary-search-tree/description/

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
    bool isValidBST(TreeNode *root)
    {
        return isBST(root);
    }

    bool isBST(TreeNode *root, TreeNode *min = NULL, TreeNode *max = NULL)
    {

        if (root == NULL)
            return true;

        if (min != NULL && root->val <= min->val)
            return false;
        if (max != NULL && root->val >= max->val)
            return false;

        bool leftValid = isBST(root->left, min, root);
        bool rightValid = isBST(root->right, root, max);

        return leftValid and rightValid;
    }
};

int main()
{
    TreeNode *t = new TreeNode(2);
    t->left = new TreeNode(1);
    t->right = new TreeNode(3);
    Solution s;
    cout << s.isValidBST(t) << endl;
}