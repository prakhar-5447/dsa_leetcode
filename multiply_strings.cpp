// https://leetcode.com/problems/multiply-strings/description/

#include <bits/stdc++.h>

#define vi vector<int>
#define vii vector<vector<int>>
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define c(a) cout << a << endl

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

    string multiply(string num1, string num2)
    {
        int len1 = num1.length() - 1;
        int len2 = num2.length() - 1;
        int zeroCount = 0;
        while (len1 >= 0 && num1[len1] == '0')
        {
            len1--;
            zeroCount++;
        }
        if (len1 < 0)
            return "0";
        int val1, val2;
        int mulCarry = 0, addCarry = 0;
        int temp;
        string res;
        string ans;
        int level = 0;
        bool valid = false;
        while (len1 >= 0)
        {
            int pos = 0;
            val1 = (int)num1[len1] - 48;
            if (!val1)
            {
                level++;
                len1--;
                continue;
            }
            while (pos < level && !res.empty())
            {
                ans.push_back(res[pos]);
                pos++;
            }
            while (len2 >= 0)
            {
                val2 = (int)num2[len2] - 48;
                temp = val1 * val2 + mulCarry;
                mulCarry = temp / 10;
                temp = temp % 10;
                if (temp || mulCarry)
                    valid = true;
                if (!res.empty() && pos < res.length())
                {
                    int addVal = temp + ((int)res[pos] - 48) + addCarry;
                    addCarry = addVal / 10;
                    addVal %= 10;
                    ans.append(to_string(addVal));
                    pos++;
                }
                else
                {
                    int addVal = temp + addCarry;
                    addCarry = addVal / 10;
                    addVal %= 10;
                    ans.append(to_string(addVal));
                }
                len2--;
            }
            if (mulCarry || addCarry)
            {
                ans.append(to_string(mulCarry + addCarry));
                mulCarry = 0;
                addCarry = 0;
            }
            res.clear();
            if (valid)
                res.append(ans);
            else
                res.append("0");
            valid = false;
            ans.clear();
            len2 = num2.length() - 1;
            len1--;
            level++;
        }
        reverseStr(res);
        while (zeroCount != 0)
        {
            res.append("0");
            zeroCount--;
        }
        return res;
    }
};

int main()
{
    Solution s;
    c(s.multiply("408", "5"));
}