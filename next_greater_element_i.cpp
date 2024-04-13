// https://leetcode.com/problems/next-greater-element-i/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {

        unordered_map<int, int> pos;
        int j = 0;
        while (j < nums2.size())
        {
            pos[nums2[j]] = j;
            j++;
        }
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++)
        {
            int value = -1;
            j = pos[nums1[i]] + 1;
            while (j < nums2.size())
            {
                if (nums2[j] > nums1[i])
                {
                    value = nums2[j];
                    break;
                }
                j++;
            }
            ans.push_back(value);
        }
        return ans;
    }
};

int main()
{
    vector<int> a = {4, 1, 2};
    vector<int> b = {1, 3, 4, 2};
    Solution s;
    vector<int> ans = s.nextGreaterElement(a, b);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}