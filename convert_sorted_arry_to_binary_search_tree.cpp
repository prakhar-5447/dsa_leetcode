// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/

#include <iostream>
#include <vector>

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
    TreeNode *convert(vector<int> &nums, int low, int high)
    {
        if (low == high)
            return new TreeNode(nums[low]);

        if (low > high)
            return NULL;

        int mid = high - (high - low) / 2;
        TreeNode *left = convert(nums, low, mid - 1);
        TreeNode *right = convert(nums, mid + 1, high);

        return new TreeNode(nums[mid], left, right);
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return convert(nums, 0, nums.size() - 1);
    }
};

void traverse(TreeNode *root)
{
    if (root == NULL)
        return;

    traverse(root->left);
    cout << root->val << " ";
    traverse(root->right);
}

int main()
{
    vector<int> a = {-10, -3, 0, 5, 9};
    Solution s;
    TreeNode *ans = s.sortedArrayToBST(a);
    traverse(ans);
}