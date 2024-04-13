// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> result;
    map<char, vector<char>> lettters = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}};

    void generate(string s, string &digits, int index)
    {
        if (digits.length() == index)
        {
            result.push_back(s);
            return;
        }

        vector<char> temp = lettters[digits[index]];
        for (int i = 0; i < temp.size(); i++)
        {
            string str = s;
            str.push_back(temp[i]);
            generate(str, digits, index + 1);
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.length())
            generate("", digits, 0);
        return result;
    }
};

int main()
{
    Solution s;
    vector<string> ans = s.letterCombinations("23");
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}