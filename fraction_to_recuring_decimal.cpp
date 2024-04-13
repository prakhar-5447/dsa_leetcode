// https://leetcode.com/problems/fraction-to-recurring-decimal/description/

#include <bits/stdc++.h>

#define vi vector<int>
#define vii vector<vector<int>>
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define c(a) cout << a << endl

using namespace std;

// class Solution
// {
// public:
//     string fractionToDecimal(int numerator, int denominator)
//     {
//         if (numerator == 0)
//             return "0";
//         string ans;
//         map<int, int> mp;
//         bool dot = false;
//         int count = -1;
//         int rem = 0;
//         do
//         {
//             if (dot)
//                 numerator *= 10;
//             count++;
//             if (numerator < denominator && !dot)
//             {
//                 if (ans.length() == 0)
//                 {
//                     ans.push_back('0');
//                     count++;
//                 }
//                 ans.push_back('.');
//                 dot = true;
//             }
//             else if (numerator < denominator)
//             {
//                 if (dot && mp[numerator])
//                     break;
//                 else if (dot)
//                     mp[numerator] = count;
//                 ans.push_back('0');
//             }
//             else
//             {
//                 if (dot && mp[numerator])
//                     break;
//                 else if (dot && numerator)
//                     mp[numerator] = count;
//                 ans.append(to_string(numerator / denominator));
//                 numerator %= denominator;
//             }

//         } while (numerator);

//         if (mp[numerator])
//         {
//             c(numerator);
//             ans.insert(mp[numerator], "(");
//             ans.push_back(')');
//         }

//         return ans;
//     }
// };

class Solution
{
public:
    string tostring(long long n)
    {
        if (n == 0)
            return "0";
        string ans;
        while (n > 0)
        {
            string dem;
            dem += ((n % 10) + '0');
            ans = dem + ans;
            n /= 10;
        }
        return ans;
    }
    string fractionToDecimal(int num, int denom)
    {
        if (num == 0)
            return "0";
        string ans;
        if ((num < 0 && denom > 0) || (num > 0 && denom < 0))
            ans.push_back('-');
        num = abs(num);
        denom = abs(denom);
        long long quotient = num / denom;
        long long remainder = num % denom;
        ans = ans + tostring(quotient);
        if (remainder == 0)
            return ans;
        ans += '.';
        map<long long, int> mp;
        while (remainder != 0)
        {
            if (mp.find(remainder) != mp.end())
            {
                int pos = mp[remainder];
                ans.insert(pos, "(");
                ans += ')';
                break;
            }
            else
            {
                mp[remainder] = ans.length();
                remainder *= 10;
                quotient = remainder / denom;
                remainder = remainder % denom;
                ans += tostring(quotient);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    c(s.fractionToDecimal(1, 6));
}