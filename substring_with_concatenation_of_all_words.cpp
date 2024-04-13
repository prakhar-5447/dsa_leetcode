// https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> a;
        int n = words.front().length();
        sort(words.begin(), words.end());
        int N = n * words.size();
        int len = s.length();
        for (int i = 0; i < len - N + 1; i++)
        {
            stringstream ss;
            for (int j = i; j < i + N; j += n)
            {
                string c = s.substr(j, n);
                ss << c;
            }
            vector<string> b;
            string str = ss.str();
            for (int k = 0; k < N; k += n)
                b.push_back(str.substr(k, n));
            sort(b.begin(), b.end());
            if (b == words)
                a.push_back(i);
        }
        return a;
    }
};

int main()
{
    vector<string> words = {"word", "good", "best", "good"};
    Solution s;
    vector<int> ans = s.findSubstring("wordgoodgoodgoodbestword", words);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}