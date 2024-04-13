// https://leetcode.com/problems/intersection-of-two-arrays/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        map<int, int> temp;
        vector<int> ans;
        int len1 = nums1.size();
        int len2 = nums2.size();
        int i;

        for (i = 0; i < len1; i++)
        {
            temp[nums1[i]]++;
        }

        for (i = 0; i < len2; i++)
        {
            if (temp[nums2[i]])
            {
                ans.push_back(nums2[i]);
                temp[nums2[i]] = 0;
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> s1 = {1, 2, 3, 4, 2, 3, 1};
    vector<int> s2 = {1, 4, 7, 8, 2, 3};
    vector<int> result = sol.intersection(s1, s2);

    vector<int>::iterator it;
    for (it = result.begin(); it != result.end(); it++)
    {
        cout << *it << " ";
    }
}