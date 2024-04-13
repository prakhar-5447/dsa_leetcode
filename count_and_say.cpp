// https://leetcode.com/problems/count-and-say/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";
        string res = countAndSay(n - 1);
        int len = 1;
        int prev = res[0];
        string s;
        int i = 1;
        for (; i < res.length(); i++)
        {
            if (res[i] != prev)
            {
                s.append(to_string(len));
                s.push_back(res[i - 1]);
                prev = res[i];
                len = 1;
            }
            else if (res[i] == prev)
                len++;
        }
        s.append(to_string(len));
        s.push_back(res[i - 1]);
        prev = res[i];
        return s;
    }
};

int main()
{
    Solution s;
    cout << s.countAndSay(2) << endl;
}