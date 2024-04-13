// https://leetcode.com/problems/maximum-depth-of-n-ary-tree/description/

#include <iostream>
#include <vector>

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
    int maxHeight = 0;
    void multiPathTraverse(Node *root, int height)
    {
        if (!root)
            return;

        maxHeight = max(maxHeight, height + 1);
        for (int i = 0; i < root->children.size(); i++)
        {
            multiPathTraverse(root->children[i], height + 1);
        }
    }

    int maxDepth(Node *root)
    {
        multiPathTraverse(root, 0);
        return maxHeight;
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
    cout << s.maxDepth(t) << endl;
}