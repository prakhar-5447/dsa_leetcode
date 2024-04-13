// https://leetcode.com/problems/symmetric-tree/description/

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
    bool checkSymmetric(TreeNode *l, TreeNode *r)
    {
        if (l == NULL && r == NULL)
            return true;

        if (l == NULL || r == NULL)
            return false;

        if (l->val == r->val)
            return checkSymmetric(l->left, r->right) && checkSymmetric(l->right, r->left);

        return false;
    }

    bool isSymmetric(TreeNode *root)
    {
        return checkSymmetric(root->left, root->right);
    }
};

int main()
{
    TreeNode *l1 = new TreeNode(1);
    TreeNode *l2 = new TreeNode(1);
    l2->left = new TreeNode(2);
    l2->right = new TreeNode(3);
    TreeNode *l3 = new TreeNode(1);
    l3->left = new TreeNode(2);
    l3->right = new TreeNode(3);
    l1->left = l3;
    l1->right = l2;

    Solution s;
    if (s.isSymmetric(l1))
    {
        cout << "tree is symmetric" << endl;
    }
    else
    {
        cout << "tree is not symmetric" << endl;
    }
}