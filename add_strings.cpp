// https://leetcode.com/problems/add-strings/description/

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

    string addStrings(string num1, string num2)
    {
        int len1 = num1.length() - 1;
        int len2 = num2.length() - 1;
        int carry = 0;
        string ans;
        int temp = 0;
        while (len1 >= 0 && len2 >= 0)
        {
            temp = num1[len1--] - '0' + (num2[len2--] - '0') + carry;
            ans.append(to_string(temp % 10));
            carry = temp / 10;
        }

        while (len1 >= 0)
        {
            temp = num1[len1--] - '0' + carry;
            ans.append(to_string(temp % 10));
            carry = temp / 10;
        }

        while (len2 >= 0)
        {
            temp = num2[len2--] - '0' + carry;
            ans.append(to_string(temp % 10));
            carry = temp / 10;
        }

        if (carry > 0)
            ans.append(to_string(carry));

        reverseStr(ans);
        return ans;
    }
};

int main()
{
    Solution s;
    string ans = s.addStrings("6", "501");
    // string ans = s.addStrings("11", "123");
    for (int i = 0; i < ans.length(); i++)
    {
        cout << ans[i];
    }
}