// https://leetcode.com/problems/guess-number-higher-or-lower//description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int guess(int num)
    {
        return 0;
    }

    int guessNumber(int n)
    {
        int low = 1, high = n, mid;
        if (guess(high) == 0)
            return high;

        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (guess(mid) == 0)
                break;
            else if (guess(mid) == -1)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return mid;
    }
};

int main()
{
    Solution sol;
    cout << sol.guessNumber(20) << endl;
}