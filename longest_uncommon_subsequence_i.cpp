// https://leetcode.com/problems/longest-uncommon-subsequence-i/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findLUSlength(string a, string b)
    {
        if (a != b)
            return max(a.length(), b.length());
        return -1;
    }
};

int main()
{
    Solution s;
    cout << s.findLUSlength("aefawfawfawfaw", "aefawfeawfwafwaef") << endl;
}