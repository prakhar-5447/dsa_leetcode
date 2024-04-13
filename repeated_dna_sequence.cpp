// https://leetcode.com/problems/repeated-dna-sequences/description/

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
    vector<string> findRepeatedDnaSequences(string s)
    {
        vector<string> ans;
        unordered_map<string, int> mp;
        for (int i = 0; i + 9 < s.length(); i++)
        {
            mp[s.substr(i, 10)]++;
            if (mp[s.substr(i, 10)] == 2)
                ans.push_back(s.substr(i, 10));
        }
        
        return ans;
    }
};

int main()
{
    Solution s;
    vector<string> res = s.findRepeatedDnaSequences("AAAAAAAAAAAAA");
    f(i, 0, res.size()) c(res[i]);
}