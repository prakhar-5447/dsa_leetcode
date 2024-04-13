// https://leetcode.com/problems/word-break/description/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool wordBreak(int index, int &maxLen, string &s, unordered_set<string> &set, vector<int> &dp)
    {
        if (index >= s.length())
            return true;

        string temp = s.substr(index, maxLen);
        while (temp.length())
        {
            if (dp[index] != -1)
                return dp[index];

            if (set.count(temp))
            {
                if (wordBreak(index + temp.length(), maxLen, s, set, dp))
                    return dp[index] = true;
            }

            temp.pop_back();
        }

        return dp[index] = false;
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        int maxLen = INT_MIN;
        for (int i = 0; i < wordDict.size(); i++)
        {
            int val = wordDict[i].length();
            maxLen = max(maxLen, val);
        }

        unordered_set<string> set(wordDict.begin(), wordDict.end());
        vector<int> dp(s.length(), -1);
        return wordBreak(0, maxLen, s, set, dp);
    }
};

int main()
{
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    Solution sol;
    cout << sol.wordBreak(s, wordDict) << endl;
}