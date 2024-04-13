// https://leetcode.com/problems/rotate-array/description/

#include <iostream>
#include <vector>
#include <algorithm>
#define vi vector<int>
#define vii vector<vector<int>>
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define c(a) cout << a << endl

using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        if (k >= nums.size())
            k %= nums.size();

        if (nums.size() == 1)
            return;

        reverse(nums.begin(), nums.end() - k);
        reverse(nums.begin() + (nums.size() - k), nums.end());
        reverse(nums.begin(), nums.end());
    }
};

int main()
{
    vector<int> arr = {1, 3, 6, 8, 5, 3, 7, 3, 2, 7, 9, 9, 7};
    Solution s;

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    s.rotate(arr, 5);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}