// https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/

#include <iostream>
#include <vector>

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
    int minAbsolute = INT_MAX;
    int prev = INT_MIN + 10000;
    void inOrder(TreeNode *root)
    {
        if (!root)
            return;

        inOrder(root->left);
        minAbsolute = min(abs(root->val - prev), minAbsolute);
        prev = root->val;
        inOrder(root->right);
    }

    int getMinimumDifference(TreeNode *root)
    {
        inOrder(root->left);
        minAbsolute = min(root->val - prev, minAbsolute);
        prev = root->val;
        inOrder(root->right);

        return minAbsolute;
    }
};

int main()
{
    TreeNode *t = new TreeNode(2);
    t->left = new TreeNode(1);
    t->right = new TreeNode(3);
    Solution s;
    cout << s.getMinimumDifference(t) << endl;
}