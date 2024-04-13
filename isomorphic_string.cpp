// https://leetcode.com/problems/isomorphic-strings/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        int len = s.length();
        map<char, char> iso1;
        map<char, char> iso2;
        for (int i = 0; i < len; i++)
        {
            if (iso1[s[i]] && iso2[t[i]])
            {
                if (t[i] != iso1[s[i]] || s[i] != iso2[t[i]])
                    return false;
            }
            else if (iso1[s[i]])
            {
                if (s[i] != iso2[t[i]])
                    return false;
                iso1[s[i]] = t[i];
            }
            else if (iso2[t[i]])
            {
                if (t[i] != iso1[s[i]])
                    return false;
                iso2[t[i]] = s[i];
            }
            else
            {
                iso1[s[i]] = t[i];
                iso2[t[i]] = s[i];
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout << s.isIsomorphic("paper", "title") << endl;
}