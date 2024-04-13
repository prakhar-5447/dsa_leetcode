// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/

#include <iostream>
#include <queue>

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
        if (root == NULL)
        {
            return root;
        }

        queue<Node *> q;

        q.push(root);
        q.push(NULL);

        while (q.size() > 1)
        {
            int n = q.size();
            for (int i = 1; i < n; i++)
            {
                Node *node = q.front();
                q.pop();

                node->next = q.front();

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            q.pop();
            q.push(NULL);
        }

        return root;
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