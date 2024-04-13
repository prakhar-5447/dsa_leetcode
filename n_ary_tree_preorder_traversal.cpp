// https://leetcode.com/problems/n-ary-tree-preorder-traversal/description/

#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    vector<int> ans;
    void preOrder(Node *root)
    {
        if (!root)
            return;

        ans.push_back(root->val);
        for (int i = 0; i < root->children.size(); i++)
            preOrder(root->children[i]);
    }

    vector<int> preorder(Node *root)
    {
        preOrder(root);
        return ans;
    }
};

int main()
{
    Node *t1 = new Node(2);
    Node *t2 = new Node(3);
    Node *t3 = new Node(4);
    Node *t4 = new Node(5);
    Node *t = new Node(2, {t1, t2, t3, t4});
    Solution s;
    vector<int> ans = s.preorder(t);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}
