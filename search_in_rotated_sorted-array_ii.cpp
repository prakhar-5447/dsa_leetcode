// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int pi = pivot(nums);
        if (pi == -1)
            return BinarySearch(nums, target, 0, nums.size() - 1);
        else
            return BinarySearch(nums, target, 0, pi) || BinarySearch(nums, target, pi + 1, nums.size() - 1);
    }

    int pivot(vector<int> arr)
    {
        int beg = 0, end = arr.size() - 1;
        if (arr.size() < 2)
            return -1;
        for (int i = 1; i <= end; i++)
        {
            if (arr[i] < arr[i - 1])
                return i - 1;
        }
        return -1;
    }

    bool BinarySearch(vector<int> arr, int num, int beg, int end)
    {
        int mid;

        if (beg > end)
            return false;
        else
        {
            mid = beg + (end - beg) / 2;

            if (arr[mid] == num)
                return true;
            else if (num > arr[mid])
                return BinarySearch(arr, num, mid + 1, end);
            else if (num < arr[mid])
                return BinarySearch(arr, num, beg, mid - 1);
        }
        return false;
    }
};

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 0, 1, 2, 3};
    Solution s;
    cout << s.search(arr, 3) << endl;
}