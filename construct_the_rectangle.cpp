// https://leetcode.com/problems/construct-the-rectangle/description/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
    vector<int> constructRectangle(int area)
    {
        int B = sqrt(area);
        int L = B;
        while (L > 0 && B <= area)
        {
            if (L * B == area)
            {
                return {B, L};
            }
            else if (L * B < area)
                B++;
            else
                L--;
        }
        return {area, 1};
    }
};

int main()
{
    Solution s;
    vector<int> ans = s.constructRectangle(122122);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}