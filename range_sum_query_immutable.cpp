// https://leetcode.com/problems/range-sum-query-immutable/description/

#include <bits/stdc++.h>

using namespace std;

class NumArray
{
public:
    vector<int> ans;
    NumArray(vector<int> &nums)
    {
        ans.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            ans.push_back(nums[i] + ans[i - 1]);
        }

        vector<int>::iterator it;
        for (it = ans.begin(); it < ans.end(); it++)
        {
            cout << (*it) << " ";
        }
        cout << endl;
    }

    int sumRange(int left, int right)
    {
        if (left == 0)
            return ans[right];
        return ans[right] - ans[left - 1];
    }
};

int main()
{
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray *obj = new NumArray(nums);
    cout << obj->sumRange(0, 2) << endl;
    cout << obj->sumRange(2, 5) << endl;
    cout << obj->sumRange(0, 5) << endl;
}