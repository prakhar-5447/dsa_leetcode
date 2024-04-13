// https://leetcode.com/problems/binary-tree-tilt/description/

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
    int sum;
    int findMinimum(TreeNode *root)
    {
        if (!root)
            return 0;

        int l = findMinimum(root->left);
        int r = findMinimum(root->right);

        sum += abs(l - r);

        return l + r + root->val;
    }

    int findTilt(TreeNode *root)
    {
        if (!root)
            return 0;
        int temp = findMinimum(root);
        return sum;
    }
};

int main()
{
    TreeNode *t = new TreeNode(2);
    t->left = new TreeNode(1);
    t->right = new TreeNode(3);
    Solution s;
    cout << s.findTilt(t) << endl;
}