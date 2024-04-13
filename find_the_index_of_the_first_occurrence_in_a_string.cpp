// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int strLen = haystack.length();
        int patternLen = needle.length();
        for (int i = 0; i <= strLen - patternLen; i++)
        {
            if (haystack[i] == needle[0])
            {
                if (haystack.substr(i, patternLen) == needle)
                {
                    return i;
                }
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    string s = "asnfnolas";
    string pattern = "asnf";

    cout << sol.strStr(s, pattern) << endl;
}
