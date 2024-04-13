// https://leetcode.com/problems/contains-duplicate-ii/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        map<int, int> temp;
        int len = nums.size();

        for (int i = 0; i < len; i++)
        {
            if (temp[nums[i]])
            {
                if (i - temp[nums[i]] + 1 <= k)
                    return true;
            }
            temp[nums[i]] = i + 1;
        }
        return false;
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 2, 3, 5, 6, 5, 9};
    Solution s;
    cout << s.containsNearbyDuplicate(arr, 3) << endl;
}