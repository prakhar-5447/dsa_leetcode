// https://leetcode.com/problems/text-justification/description/

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
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> res;
        int count = words[0].length();
        int weight = words[0].length();
        int start = 0;
        for (int i = 1; i < words.size(); i++)
        {
            if (count + words[i].length() + 1 <= maxWidth)
            {
                count = count + words[i].length() + 1;
                weight += words[i].length();
            }
            else
            {
                if (i - start == 1)
                    leftJustify(res, words, start, i - 1, maxWidth);
                else
                    justify(res, words, weight, start, i - 1, maxWidth);
                count = words[i].length();
                start = i;
                weight = words[i].length();
            }
        }
        leftJustify(res, words, start, words.size() - 1, maxWidth);
        return res;
    }

    void justify(vector<string> &res, vector<string> &words, int w, int start, int end, int maxWidth)
    {
        int spacing = maxWidth - w;
        int itemCount = end - start;
        int insertSpaces = spacing / itemCount;
        int extraSpaces = spacing % itemCount;
        string c;
        for (int i = start; i < end; i++)
        {
            c.append(words[i]);
            insertSpace(c, insertSpaces);
            if (extraSpaces)
            {
                insertSpace(c, 1);
                extraSpaces--;
            }
        }
        c.append(words[end]);
        res.push_back(c);
    }

    void leftJustify(vector<string> &res, vector<string> &words, int start, int end, int maxWidth)
    {
        string c;
        for (int i = start; i <= end; i++)
        {
            c.append(words[i]);
            if (c.length() != maxWidth)
                insertSpace(c, 1);
        }
        insertSpace(c, maxWidth - c.length());
        res.push_back(c);
    }

    void insertSpace(string &c, int count)
    {
        for (int i = 0; i < count; i++)
            c.append(" ");
    }
};

int main()
{
    vector<string> a = {"Science", "is", "what", "we", "understand", "well", "enough", "to", "explain", "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"};
    Solution s;
    vector<string> ans = s.fullJustify(a, 20);
    f(i, 0, ans.size())
        c(ans[i]);
}