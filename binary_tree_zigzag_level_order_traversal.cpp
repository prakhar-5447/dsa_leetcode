// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

#include <iostream>
#include <vector>
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

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (root == NULL)
        {
            return {};
        }

        vector<vector<int>> ans;
        vector<int> res;
        stack<TreeNode *> s;
        stack<TreeNode *> q;

        q.push(root);

        while (!q.empty() || !s.empty())
        {
            if (s.empty())
            {
                int n = q.size();
                for (int i = 1; i <= n; i++)
                {
                    TreeNode *node = q.top();
                    q.pop();

                    res.push_back(node->val);

                    if (node->left)
                        s.push(node->left);
                    if (node->right)
                        s.push(node->right);
                }
            }
            else
            {
                int n = s.size();
                for (int i = 1; i <= n; i++)
                {
                    TreeNode *node = s.top();
                    s.pop();

                    res.push_back(node->val);

                    if (node->right)
                        q.push(node->right);
                    if (node->left)
                        q.push(node->left);
                }
            }
            ans.push_back(res);
            res.clear();
        }

        return ans;
    }
};

int main()
{
    TreeNode *t = new TreeNode(2);
    t->left = new TreeNode(1);
    t->right = new TreeNode(3);
    Solution s;
    vector<vector<int>> ans = s.zigzagLevelOrder(t);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}