// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

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
    TreeNode *construct(int &idk, int start, int end, vector<int> &inorder, vector<int> &postorder)
    {
        if (start > end || idk < 0)
            return NULL;
        int element = postorder[idk];
        idk--;
        int pos = linearSearch(element, inorder);
        TreeNode *head = new TreeNode(element);
        head->right = construct(idk, pos + 1, end, inorder, postorder);
        head->left = construct(idk, start, pos - 1, inorder, postorder);
        return head;
    }

    int linearSearch(int element, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            if (element == inorder[i])
                return i;
        }
        return -1;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        TreeNode *root;
        int n = inorder.size();
        int lastpos = n - 1;
        root = construct(lastpos, 0, n - 1, inorder, postorder);
        return root;
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
    vi inorder = {9, 3, 15, 20, 7}, postorder = {9, 15, 7, 20, 3};
    Solution s;
    TreeNode *ptr = s.buildTree(postorder, inorder);
    s.traverse(ptr);
}