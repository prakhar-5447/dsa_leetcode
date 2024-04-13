// https://leetcode.com/problems/merge-sorted-array/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m + n - 1, j = m - 1, k = n - 1;
        while (k >= 0)
        {
            if (j >= 0 && nums1[j] > nums2[k])
                nums1[i--] = nums1[j--];
            else
                nums1[i--] = nums2[k--];
        }
    }
};

int main()
{
    vector<int> a = {1, 2, 3, 0, 0, 0};
    vector<int> b = {2, 5, 6};
    Solution s;
    s.merge(a, a.size() - b.size(), b, b.size());
    vector<int>::iterator it;
    for (it = a.begin(); it < a.end(); it++)
    {
        cout << (*it) << " ";
    }
}