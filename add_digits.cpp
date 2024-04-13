// https://leetcode.com/problems/add-digits/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int addDigits(int num)
    {
        int ans = 0;
        while (true)
        {
            if (!num)
            {
                num = ans;
                ans = 0;
                if (num <= 9)
                    return num;
            }

            int temp = num % 10;
            ans += temp;
            num /= 10;
        }
        return num;
    }
};

// class Solution
// {
// public:
//     int addDigits(int num)
//     {
//         int ans = 0;
//         while (num != 0)
//         {
//             int temp = num % 10;
//             ans += temp;
//             num /= 10;
//         }
//         if (ans <= 9)
//             return ans;

//         return addDigits(ans);
//     }
// };

int main()
{
    Solution s;
    cout << s.addDigits(38) << endl;
}