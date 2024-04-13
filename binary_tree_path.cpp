// https://leetcode.com/problems/binary-tree-paths/description/

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
    vector<string> ans;
    void traverse(TreeNode *root, string temp)
    {
        if (temp.length() == 0)
            temp.append(to_string(root->val));
        else
            temp.append("->" + to_string(root->val));

        if (root->left != NULL && root->right != NULL)
        {
            traverse(root->left, temp);
            traverse(root->right, temp);
        }
        else if (root->left != NULL)
        {
            traverse(root->left, temp);
        }
        else if (root->right != NULL)
        {
            traverse(root->right, temp);
        }
        else
        {
            ans.push_back(temp);
        }

        return;
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        traverse(root, "");
        return ans;
    }
};

int main()
{
    TreeNode *t = new TreeNode(2);
    t->left = new TreeNode(1);
    t->right = new TreeNode(3);
    Solution s;
    vector<string> ans = s.binaryTreePaths(t);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}