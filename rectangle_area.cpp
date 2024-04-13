// https://leetcode.com/problems/rectangle-area/description/

#include <bits/stdc++.h>

#define vi vector<int>
#define vii vector<vector<int>>
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define c(a) cout << a << endl

using namespace std;

class Solution
{
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
    {
        int a1 = abs(ax2 - ax1) * abs(ay2 - ay1);
        int a2 = abs(bx2 - bx1) * abs(by2 - by1);
        int p = min(ax2, bx2);
        int q = max(ax1, bx1);
        int r = min(ay2, by2);
        int s = max(ay1, by1);
        int inter = (p - q) * (r - s);
        cout << a1 << " " << a2 << " " << inter << endl;
        if ((bx1) > (ax2) || (by1) > (ay2) || (bx2) < (ax1) || (by2) < (ay1))
            return a1 + a2;

        else
            return a1 + a2 - inter;
    }
};

int main()
{
    Solution s;
    c(s.computeArea(-3, 0, 3, 4, 0, -1, 9, 2));
}