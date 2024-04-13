// https://leetcode.com/problems/binary-search-tree-iterator/description/

#include <iostream>
#include <stack>

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

class BSTIterator
{
    stack<TreeNode *> myStack;

public:
    BSTIterator(TreeNode *root)
    {
        pushAll(root);
    }

    bool hasNext()
    {
        return !myStack.empty();
    }

    int next()
    {
        TreeNode *tmpNode = myStack.top();
        myStack.pop();
        pushAll(tmpNode->right);
        return tmpNode->val;
    }

    void pushAll(TreeNode *node)
    {
        for (; node != NULL; myStack.push(node), node = node->left)
            ;
    }
};

int main()
{
    TreeNode *t = new TreeNode(2);
    BSTIterator s = BSTIterator(t);
}