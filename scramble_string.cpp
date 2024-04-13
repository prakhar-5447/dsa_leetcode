// https://leetcode.com/problems/scramble-string/descriptions/

#include <iostream>
#include <unordered_map>
#define vi vector<int>
#define vii vector<vector<int>>
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define c(a) cout << a << endl

using namespace std;

class Solution
{
public:
    unordered_map<string, bool> mp;
    bool isScramble(string s1, string s2)
    {
        if (s1 == s2)
            return true;

        string key = s1 + "*" + s2;

        if (mp.count(key))
            return mp[key];

        for (int i = 0; i < s1.size() - 1; i++)
        {
            if (isScramble(s1.substr(0, i + 1), s2.substr(0, i + 1)) && isScramble(s1.substr(i + 1), s2.substr(i + 1)))
                return mp[key] = true;

            if (isScramble(s1.substr(0, i + 1), s2.substr(s2.size() - i - 1)) && isScramble(s1.substr(i + 1), s2.substr(0, s2.size() - i - 1)))
                return mp[key] = true;
        }

        return mp[key] = false;
    }
};

int main()
{
    Solution s;
    c(s.isScramble("great", "rgeat"));
}