// https://leetcode.com/problems/happy-number/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        unsigned long long int temp = 0, ans = 0;
        map<int, int> present;
        while (true)
        {
            if (n)
            {
                temp = n % 10;
                ans += (temp * temp);
                n /= 10;
            }
            else
            {
                if (present[ans])
                    break;
                n = ans;
                if (n == 1)
                    return (ans == 1);
                present[n] = 1;
                ans = 0;
            }
        }
        return (ans == 1);
    }
};

int main()
{
    Solution s;
    cout << s.isHappy(19) << endl;
}