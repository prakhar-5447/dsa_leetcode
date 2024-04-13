// https://leetcode.com/problems/valid-perfect-square/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        if (num == 1)
            return true;

        int low = 1, high = 0, mid, temp = num, count = 0;

        while (temp)
        {
            count++;
            temp /= 10;
            if (count % 2 == 0)
                high = high * 10 + 9;
        }

        if (count >= 1)
        {
            if (count % 2)
                high = high * 10 + 9;
        }

        while (low <= high)
        {
            mid = low + (high - low) / 2;
            int sqr = num / mid;
            if (num % mid == 0 && num / mid == mid)
                return true;
            else if (num / mid < mid)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return false;
    }
};

int main()
{
    Solution sol;
    cout << sol.isPerfectSquare(16) << endl;
}