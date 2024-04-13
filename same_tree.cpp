// https://leetcode.com/problems/same-tree/description/

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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL)
            return true;

        if (p == NULL || q == NULL)
            return false;

        if (p->val == q->val)
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

        return false;
    }
};

int main()
{
    TreeNode *l1 = new TreeNode(1);
    l1->left = new TreeNode(2);
    l1->right = new TreeNode(3);
    TreeNode *l2 = new TreeNode(1);
    l2->left = new TreeNode(2);
    l2->right = new TreeNode(3);

    Solution s;
    if (s.isSameTree(l1, l2))
        cout << "both tree are same" << endl;
    else
        cout << "both tree are not same" << endl;
}