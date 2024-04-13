// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/

#include <iostream>

using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node *_left, Node *_right, Node *_next) : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        connect(root, NULL);
        return root;
    }

    void connect(Node *root, Node *temp)
    {
        if (!root)
            return;

        root->next = temp;
        connect(root->left, root->right);
        if (temp)
            connect(root->right, temp->left);
        else
            connect(root->right, NULL);
    }

    void traverse(Node *root)
    {
        if (root == NULL)
            return;

        traverse(root->left);
        cout << root->val << " ";
        traverse(root->right);
    }
};

int main()
{
    Node *t = new Node(2);
    t->left = new Node(1);
    t->right = new Node(3);
    Solution s;
    Node *ans = s.connect(t);
    s.traverse(ans);
}