// https://leetcode.com/problems/single-number/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int n = nums[0];
        int len = nums.size();
        for (int i = 1; i < len; i++)
        {
            n ^= nums[i];
        }
        return n;
    }
};

int main()
{
    vector<int> n = {4, 1, 2, 1, 2};
    Solution s;
    cout << s.singleNumber(n) << endl;
}