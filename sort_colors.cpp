// https://leetcode.com/problems/sort-colors/description/

#include <iostream>
#include <vector>
#define vi vector<int>
#define vii vector<vector<int>>
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define c(a) cout << a << endl

using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int l = 0;
        int m = 0;
        int h = nums.size() - 1;

        while (m <= h)
        {
            if (nums[m] == 0)
            {
                swap(nums[l], nums[m]);
                l++;
                m++;
            }
            else if (nums[m] == 1)
                m++;
            else if (nums[m] == 2)
            {
                swap(nums[m], nums[h]);
                h--;
            }
        }
    }
};

int main()
{
    vi a = {1, 2, 2, 2, 2, 2, 1, 1, 0, 0, 1, 0};
    Solution s;
    s.sortColors(a);
    f(i, 0, a.size())
    {
        c(a[i]);
    }
}