// https://leetcode.com/problems/jump-game-ii/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 0;
        for (int i = 1; i < nums.size(); i++)
            nums[i] = max(nums[i] + i, nums[i - 1]);

        int ind = 0;
        int ans = 0;

        while (ind < nums.size() - 1)
        {
            ans++;
            ind = nums[ind];
        }
        return ans;
    }
};

int main()
{
    vector<int> a = {2, 3, 1, 1, 4};
    Solution s;
    cout << s.jump(a) << endl;
}