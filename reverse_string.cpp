// https://leetcode.com/problems/reverse-string/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int i = 0, j = s.size();
        while (i < j - i)
        {
            swap(s[i], s[j - i - 1]);
            i++;
        }
    }
};

int main()
{
    vector<char> ans = {'H', 'a', 'n', 'n', 'a', 'h'};
    Solution s;
    s.reverseString(ans);
    vector<char>::iterator it;
    for (it = ans.begin(); it < ans.end(); it++)
    {
        cout << (*it) << " ";
    }
}