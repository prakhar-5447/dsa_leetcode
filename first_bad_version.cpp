// https://leetcode.com/problems/first-bad-version/description/

#include <iostream>

using namespace std;

class Solution
{
public:
    bool isBadVersion(int version)
    {
        return true;
    };

    int firstBadVersion(int n)
    {
        int low = 1, high = n, mid;
        while (low < high)
        {
            mid = low + (high - low) / 2;
            if (isBadVersion(mid))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};

int main()
{
    Solution sol;
    cout << sol.firstBadVersion(10) << endl;
}