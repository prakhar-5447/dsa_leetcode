// https://leetcode.com/problems/minimum-window-substring/description/

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
    string minWindow(string s, string t)
    {
        vector<int> map(128, 0);
        for (char c : t)
            map[c]++;

        int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
        while (end < s.size())
        {
            if (map[s[end++]]-- > 0)
                counter--;
            while (counter == 0)
            {
                if (end - begin < d)
                {
                    head = begin;
                    d = end - head;
                }
                if (map[s[begin++]]++ == 0)
                    counter++;
            }
        }
        return d == INT_MAX ? "" : s.substr(head, d);
    }
};

int main()
{
    Solution s;
    c(s.minWindow("ADOBECODEBANC", "ABC"));
}
