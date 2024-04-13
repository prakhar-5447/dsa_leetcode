// https://leetcode.com/problems/convert-a-number-to-hexadecimal/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void reverseStr(string &str)
    {
        int n = str.length();
        for (int i = 0; i < n / 2; i++)
            swap(str[i], str[n - i - 1]);
    }

    string isHexChar(int n)
    {
        switch (n)
        {
        case 0 ... 9:
            return to_string(n);
        case 10:
            return "a";
        case 11:
            return "b";
        case 12:
            return "c";
        case 13:
            return "d";
        case 14:
            return "e";
        case 15:
            return "f";
        }

        return 0;
    }

    string toHex(int num)
    {

        if (num == 0)
            return to_string(0);

        if (num < 0)
        {
            unsigned long int t = 2 * (long long)INT_MAX + 1 + num + 1;
            string temp;
            while (t)
            {
                temp.append(isHexChar(t % 16));
                t /= 16;
            }
            reverseStr(temp);
            return temp;
        }

        string temp;
        while (num)
        {
            temp.append(isHexChar(num % 16));
            num /= 16;
        }
        reverseStr(temp);
        return temp;
    }
};

int main()
{
    Solution s;
    string ans = s.toHex(-3);
    for (int i = 0; i < ans.length(); i++)
    {
        cout << ans[i] << endl;
    }
}