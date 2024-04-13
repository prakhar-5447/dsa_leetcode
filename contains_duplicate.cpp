// https://leetcode.com/problems/contains-duplicate/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        map<int, bool> temp;
        vector<int>::iterator *it;

        for (auto it = nums.begin(); it != nums.end(); it++)
        {
            if (temp[*it])
                return true;
            temp[*it] = true;
        }

        return false;
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 2, 3, 5, 6, 5, 9};
    Solution s;
    cout << s.containsDuplicate(arr) << endl;
}