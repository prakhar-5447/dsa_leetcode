// https://leetcode.com/problems/keyboard-row/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int find(char s)
    {
        if (s >= 65 && s <= 90)
            s = s + 32;

        if (s == 'q' || s == 'w' || s == 'e' || s == 'r' || s == 't' || s == 'y' || s == 'u' || s == 'i' || s == 'o' || s == 'p')
            return 1;
        else if (s == 'a' || s == 's' || s == 'd' || s == 'f' || s == 'g' || s == 'h' || s == 'j' || s == 'k' || s == 'l')
            return 2;
        return 3;
    }

    bool valid(string s)
    {
        int j = s.length() - 1;
        int row = find(s[j--]);
        while (j >= 0)
        {
            if (find(s[j]) != row)
                return false;
            j--;
        }

        return true;
    }

    vector<string> findWords(vector<string> &words)
    {
        vector<string> ans = {};
        for (int i = 0; i < words.size(); i++)
        {
            if (valid(words[i]))
            {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};

int main()
{
    vector<string> a = {"Hello", "Alaska", "Dad", "Peace"};
    Solution s;
    vector<string> ans = s.findWords(a);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}