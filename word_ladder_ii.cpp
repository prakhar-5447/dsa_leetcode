// https://leetcode.com/problems/word-ladder-ii/description/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class Solution
{
public:
    unordered_set<string> dic;
    unordered_map<string, int> mp;
    vector<vector<string>> ans;
    void dfs(string ew, vector<string> &temp, string bw)
    {

        int curr = mp[ew];
        temp.push_back(ew);
        if (ew == bw)
        {
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            reverse(temp.begin(), temp.end());
            temp.pop_back();
            return;
        }
        for (int i = 0; i < ew.size(); i++)
        {
            string st = ew;
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                st[i] = ch;
                if (mp[st] and mp[st] == curr - 1)
                    dfs(st, temp, bw);
            }
        }
        temp.pop_back();
    }

    vector<vector<string>> findLadders(string bw, string ew, vector<string> &wl)
    {

        for (auto it : wl)
            dic.insert(it);
        queue<string> q;
        q.push(bw);
        mp[bw]++;
        while (!q.empty())
        {
            auto k = q.front();
            q.pop();
            int steps = mp[k] + 1;
            for (int i = 0; i < k.size(); i++)
            {
                string temp = k;
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    temp[i] = ch;
                    if (dic.count(temp) and !mp[temp])
                    {
                        mp[temp] = steps;
                        q.push(temp);
                    }
                }
            }
        }
        if (mp[ew])
        {
            vector<string> temp;
            dfs(ew, temp, bw);
        }
        return ans;
    }
};

int main()
{
    string beginWord = "hot", endWord = "dog";
    vector<string> wordList = {"hot", "dog", "cog", "pot", "dot"};
    Solution sol;
    vector<vector<string>> ans = sol.findLadders(beginWord, endWord, wordList);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}