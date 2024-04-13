// https://leetcode.com/problems/median-of-two-sorted-arrays/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int len = nums1.size() + nums2.size();
        vector<int> temp(len);
        int i = 0, j = 0, k = 0;

        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] > nums2[j])
                temp[k++] = nums2[j++];
            else
                temp[k++] = nums1[i++];
        }

        while (i < nums1.size())
            temp[k++] = nums1[i++];

        while (j < nums2.size())
            temp[k++] = nums2[j++];

        if (len % 2)
            return temp[(len - 1) / 2];
        return (temp[(len - 1) / 2] + temp[(len - 1) / 2 + 1]) / 2.0;
    }
};

int main()
{
    Solution s;
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7};
    vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7};
    cout << s.findMedianSortedArrays(arr1, arr2) << endl;
}