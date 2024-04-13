// https://leetcode.com/problems/summary-ranges/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        int len = nums.size();
        if (!len)
            return {};
        int temp = nums[0], count = 1, i;
        vector<string> ans;
        for (i = 1; i < len; i++)
        {
            if (nums[i] != nums[i - 1] + 1)
            {
                if (count == 1)
                    ans.push_back(to_string(nums[i - 1]));
                else
                    ans.push_back(to_string(temp) + "->" + to_string(nums[i - 1]));
                temp = nums[i];
                count = 1;
            }
            else
            {
                count++;
            }
        }

        if (count == 1)
            ans.push_back(to_string(nums[i - 1]));
        else
            ans.push_back(to_string(temp) + "->" + to_string(nums[i - 1]));
            
        return ans;
    }
};

int main()
{
    vector<int> a = {0, 1, 2, 4, 5, 7};
    Solution s;
    vector<string> ans = s.summaryRanges(a);
    vector<string>::iterator it;
    for (it = ans.begin(); it < ans.end(); it++)
    {
        cout << (*it) << " ";
    }
}