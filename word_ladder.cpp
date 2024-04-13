// https://leetcode.com/problems/word-ladder/description/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

// class Solution
// {
// public:
//     bool adjacentPair(string a, string b)
//     {
//         bool check = false;
//         for (int i = 0; i < a.length(); i++)
//         {
//             if (a[i] != b[i])
//             {
//                 if (check)
//                     return false;
//                 check = true;
//             }
//         }
//         return true;
//     }

//     int ladderLength(string beginWord, string endWord, vector<string> &wordList, vector<bool> &visited, map<string, int> &dp, int count, int index)
//     {
//         int minVal = INT_MAX;

//         if (dp[beginWord])
//             return dp[beginWord];

//         if (beginWord == endWord)
//             return count;

//         for (int i = 0; i < wordList.size(); i++)
//         {
//             if (visited[i] || dp[wordList[i]] == INT_MAX)
//                 continue;

//             if (beginWord == wordList[i])
//             {
//                 visited[i] = true;
//                 dp[beginWord] = INT_MAX;
//                 continue;
//             }

//             if (adjacentPair(beginWord, wordList[i]))
//             {
//                 visited[i] = true;
//                 minVal = min(minVal, ladderLength(wordList[i], endWord, wordList, visited, dp, count + 1, index));
//                 dp[beginWord] = min(dp[beginWord], minVal - count);
//                 visited[i] = false;
//             }
//         }
//         if (minVal == INT_MAX)
//             visited[index] = true;
//         return minVal;
//     }

//     int ladderLength(string beginWord, string endWord, vector<string> &wordList)
//     {
//         vector<bool> visited(wordList.size(), false);
//         map<string, int> dp;
//         int ans = ladderLength(beginWord, endWord, wordList, visited, dp, 1, 0);
//         return ans == INT_MAX ? 0 : ans;
//     }
// };

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        st.erase(beginWord);

        while (!q.empty())
        {
            string word = q.front().first;
            int steps = q.front().second;
            if (word == endWord)
                return steps;
            q.pop();
            for (int i = 0; i < word.size(); i++)
            {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (st.find(word) != st.end())
                    {
                        st.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};

int main()
{
    string beginWord = "hot", endWord = "dog";
    vector<string> wordList = {"hot", "dog", "cog", "pot", "dot"};
    Solution sol;
    cout << sol.ladderLength(beginWord, endWord, wordList) << endl;
}