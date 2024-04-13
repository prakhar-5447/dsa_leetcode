// https://leetcode.com/problems/longest-substring-without-repeating-characters/description

#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> temp;
        string ans;
        int maxVal = 0;
        int i = 0, len;

        for (int j = 0; j < s.length();)
        {
            if (temp[s[j]])
            {
                len = ans.length();
                maxVal = max(maxVal, len);
                int index = temp[s[i]] - 1;
                while (i <= index)
                {
                    temp.erase(ans[0]);
                    ans.erase(0, 1);
                    i++;
                }
            }
            else
            {
                ans += s[j];
                temp[s[j]] = j + 1;
                j++;
            }
        }

        len = ans.length();
        maxVal = max(maxVal, len);

        return maxVal;
    }
};

int main()
{
    Solution s;
    cout << s.lengthOfLongestSubstring("sanfndfj") << endl;
}