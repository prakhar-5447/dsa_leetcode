// https://leetcode.com/problems/reverse-words-in-a-string/description/

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
    string reverseWords(string s)
    {
        string ans;
        int count = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == ' ')
            {
                if (count && ans.length() != 0)
                    ans.push_back(' ');
                ans.append(s.substr(i + 1, count));
                count = 0;
            }
            else
            {
                count++;
            }
        }
        if (count && ans.length() != 0)
            ans.push_back(' ');
        ans.append(s.substr(0, count));
        return ans;
    }
};

int main()
{
    Solution s;
    string ans = s.reverseWords("       Let's take LeetCode contest");
    cout << ans << endl;
}