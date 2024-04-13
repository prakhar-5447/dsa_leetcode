// https://leetcode.com/problems/find-mode-in-binary-search-tree/description/

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
    unordered_map<int, vector<int>> ans;
    int prev = INT_MIN;
    int count = 0;
    int freq = 0;

    void inorderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return;

        inorderTraversal(root->left);
        if (root->val > prev)
        {
            freq = max(freq, count);
            if (prev != INT_MIN)
                ans[count].push_back(prev);
            count = 1;
            prev = root->val;
        }
        else if (root->val == prev)
            count++;

        inorderTraversal(root->right);
        return;
    }

    vector<int> findMode(TreeNode *root)
    {
        inorderTraversal(root);
        freq = max(freq, count);
        ans[count].push_back(prev);
        return ans[freq];
    }
};

int main()
{
    TreeNode *t = new TreeNode(2);
    t->left = new TreeNode(1);
    t->right = new TreeNode(3);
    Solution s;
    vector<int> ans = s.findMode(t);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}