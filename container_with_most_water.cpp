// https://leetcode.com/problems/container-with-most-water/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int maxArea = 0;
        int i = 0;
        int j = height.size() - 1;
        while (i < j)
        {
            int area = (j - i) * min(height[i], height[j]);
            maxArea = max(area, maxArea);
            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return maxArea;
    }
};

int main()
{
    vector<int> a = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution s;
    cout << s.maxArea(a) << endl;
}