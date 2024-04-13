// https://leetcode.com/problems/binary-tree-preorder-traversal/description/

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

class Solution {
public:
   void traverse(vector<int> &path, TreeNode *root)
    {
        if (root == NULL)
            return;

        path.push_back(root->val);
        traverse(path, root->left);
        traverse(path, root->right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        traverse(res,root);
        return res;
    }


};

int main()
{
    TreeNode *t = new TreeNode(2);
    t->left = new TreeNode(1);
    t->right = new TreeNode(3);
    Solution s;
    vector<int> ans = s.preorderTraversal(t);
    vector<int>::iterator it;
    for (it = ans.begin(); it < ans.end(); it++)
    {
        cout << (*it) << " ";
    }
}