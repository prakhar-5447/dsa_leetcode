// https://leetcode.com/problems/generate-parentheses/description/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    unordered_set<string> result;
    void generate(string s, int n)
    {
        if (n == 0)
        {
            result.insert(s);
            return;
        }

        for (int i = 0; i <= s.length() / 2; i++)
        {
            string temp = s;
            temp.insert(i, "()");
            generate(temp, n - 1);
        }
    }

    vector<string> generateParenthesis(int n)
    {
        generate("", n);
        vector<string> ans(result.begin(), result.end());
        return ans;
    }
};

int main()
{
    Solution s;
    vector<string> ans = s.generateParenthesis(3);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}