// https://leetcode.com/problems/binary-tree-level-order-traversal/description/

#include <iostream>
#include <vector>
#include <queue>

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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == NULL)
            return {};
        

        queue<TreeNode *> q;
        vector<vector<int>> ans;
        vector<int> res;

        q.push(root);

        while (!q.empty())
        {
            int n = q.size();
            for (int i = 1; i <= n; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                res.push_back(node->val);

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
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
    vector<vector<int>> ans = s.levelOrder(t);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}