// https://leetcode.com/problems/group-anagrams/description/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define vi vector<int>
#define vii vector<vector<int>>
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define c(a) cout << a << endl

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {

        map<string, vector<string>> mp;
        vector<vector<string>> ans;

        for (int i = 0; i < strs.size(); i++)
        {
            string s = strs[i];
            sort(strs[i].begin(), strs[i].end());

            mp[strs[i]].push_back(s);
        }

        for (auto &it : mp)
            ans.push_back(it.second);

        return ans;
    }
};

int main()
{
    vector<string> arr = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution s;
    vector<vector<string>> ans = s.groupAnagrams(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            c(ans[i][j]);
        }
        cout << endl;
    }
}