// https://leetcode.com/problems/jump-game/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int target = 0;
        for (int i = 0; i <= target; i++)
        {
            target = max(target, i + nums[i]);

            if (target >= nums.size() - 1)
                return true;
        }
        return false;
    }
};

int main()
{
    vector<int> a = {2, 3, 1, 1, 4};
    Solution s;
    cout << s.canJump(a) << endl;
}