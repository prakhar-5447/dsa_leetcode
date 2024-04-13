// https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

#include <iostream>
#include <algorithm>

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
    int maxVal = INT_MIN;
    int pathSum(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int l = pathSum(root->left);
        int r = pathSum(root->right);

        if (l < 0 && r < 0)
        {
            maxVal = max(maxVal, root->val);
            return root->val;
        }
        else if (r < 0)
        {
            maxVal = max(maxVal, root->val + l);
            return root->val + l;
        }
        else if (l < 0)
        {
            maxVal = max(maxVal, root->val + r);
            return root->val + r;
        }
        else
        {
            maxVal = max(maxVal, root->val + l + r);
            if (l > r)
                return root->val + l;
            else
                return root->val + r;
        }
    }

    int maxPathSum(TreeNode *root)
    {
        int temp = pathSum(root);
        return maxVal;
    }
};

int main()
{
    TreeNode *t = new TreeNode(2);
    t->left = new TreeNode(1);
    t->right = new TreeNode(3);
    Solution s;
    cout << s.maxPathSum(t) << endl;
}