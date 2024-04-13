// https://leetcode.com/problems/add-binary/description/

#include <iostream>

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

    string addBinary(string a, string b)
    {
        string ans = "";
        int aSize = a.length() - 1;
        int bSize = b.length() - 1;
        int i = 0;
        int carry = 0;
        while (i <= aSize && i <= bSize)
        {
            if (a[aSize - i] == '0' && b[bSize - i] == '0')
            {
                if (carry)
                {
                    ans.push_back('1');
                    carry = 0;
                }
                else
                    ans.push_back('0');
            }
            else if ((a[aSize - i] == '0' && b[bSize - i] == '1') || (a[aSize - i] == '1' && b[bSize - i] == '0'))
            {
                if (carry)
                    ans.push_back('0');
                else
                    ans.push_back('1');
            }
            else
            {
                if (carry)
                    ans.push_back('1');

                else
                {
                    ans.push_back('0');
                    carry = 1;
                }
            }
            i++;
        }

        if (aSize > bSize)
        {
            int len = aSize - bSize - 1;
            while (len >= 0)
            {
                if (!carry)
                    ans.push_back(a[len]);
                else
                {
                    if (a[len] == '0')
                    {
                        ans.push_back('1');
                        carry = 0;
                    }
                    else
                        ans.push_back('0');
                }
                len--;
            }
        }
        else
        {
            int len = bSize - aSize - 1;
            while (len >= 0)
            {
                if (!carry)
                    ans.push_back(b[len]);
                else
                {
                    if (b[len] == '0')
                    {
                        ans.push_back('1');
                        carry = 0;
                    }
                    else
                        ans.push_back('0');
                }
                len--;
            }
        }

        if (carry)
        {
            ans.push_back('1');
            carry = 0;
        }
        reverseStr(ans);

        return ans;
    }
};

int main()
{
    string s1 = "11", s2 = "1";
    Solution s;
    cout << s.addBinary(s1, s2) << endl;
}