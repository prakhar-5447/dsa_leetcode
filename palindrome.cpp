// https://leetcode.com/problems/palindrome-number/description/

#include <iostream>

using namespace std;

// class Solution
// {
// public:
//     bool isPalindrome(int x)
//     {
//         long int ans = 0;
//         int temp = 0;
//         int res = x;
//         if (x < 0)
//         {
//             return false;
//         }

//         while (x)
//         {
//             temp = x % 10;
//             ans = ans * 10 + temp;
//             x /= 10;
//         }

//       if (ans == res)
//         {
//             return true;
//         }
//         return false;
//     }
// };

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }
        string s = to_string(x);
        int n = s.length();
        if (n==1){
            return true;
        }
        for (int i = 0; i < n / 2; i++)
        {
            if (s[i] != s[n - i - 1])
                return false;
        }

        return true;
    }
};

int main()
{
    int x;
    cin >> x;
    Solution s;
    cout << s.isPalindrome(x) << endl;
}