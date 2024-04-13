// https://leetcode.com/problems/trapping-rain-water/description/

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
    int trap(vector<int> &height)
    {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int res = 0;
        int maxleft = 0;
        int maxright = 0;
        while (left <= right)
        {
            if (height[left] < height[right])
            {
                if (height[left] > maxleft)
                    maxleft = height[left];
                else
                    res = res + maxleft - height[left];
                left++;
            }
            else
            {
                if (height[right] > maxright)
                    maxright = height[right];
                else
                    res = res + maxright - height[right];
                right--;
            }
        }
        return res;
    }
};

int main()
{
    vi a = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution s;
    c(s.trap(a));
}