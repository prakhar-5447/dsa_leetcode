// https://leetcode.com/problems/unique-binary-search-trees-ii/description/

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
    vector<TreeNode *> solve(int st, int e)
    {
        if (e < st)
        {
            vector<TreeNode *> nil;
            nil.push_back(NULL);
            return nil;
        }
        vector<TreeNode *> ans;
        for (int i = st; i <= e; i++)
        {
            vector<TreeNode *> left = solve(st, i - 1);
            vector<TreeNode *> right = solve(i + 1, e);

            for (auto l : left)
            {
                for (auto r : right)
                {
                    TreeNode *temp = new TreeNode(i);
                    temp->left = l;
                    temp->right = r;
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }

    vector<TreeNode *> generateTrees(int n)
    {
        return solve(1, n);
    }

    void traverse(TreeNode *root)
    {
        if (root == NULL)
            return;

        cout << root->val << "-->";
        traverse(root->left);
        traverse(root->right);
    }
};

int main()
{
    Solution s;
    vector<TreeNode *> ans = s.generateTrees(4);
    for (int i = 0; i < ans.size(); i++)
    {
        s.traverse(ans[i]);
        c(" ");
    }
    c(ans.size());
}