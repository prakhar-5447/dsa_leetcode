// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

#include <bits/stdc++.h>

#define vi vector<int>
#define vii vector<vector<int>>
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define c(a) cout << a << endl

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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int i = 0;
        return construct(preorder, inorder, 0, inorder.size() - 1, i);
    }

    TreeNode *construct(vector<int> &preorder, vector<int> &inorder, int start, int end, int &i)
    {
        if (start > end)
            return NULL;
        int pos = start;
        while (inorder[pos] != preorder[i])
            pos++;

        i++;
        TreeNode *head = new TreeNode(inorder[pos]);
        head->left = construct(preorder, inorder, start, pos - 1, i);
        head->right = construct(preorder, inorder, pos + 1, end, i);
        return head;
    }

    void traverse(TreeNode *root)
    {
        if (root == NULL)
            return;

        traverse(root->left);
        cout << root->val << endl;
        traverse(root->right);
    }
};

int main()
{
    vi preorder = {3, 9, 20, 15, 7}, inorder = {9, 3, 15, 20, 7};
    Solution s;
    TreeNode *ptr = s.buildTree(preorder, inorder);
    s.traverse(ptr);
}