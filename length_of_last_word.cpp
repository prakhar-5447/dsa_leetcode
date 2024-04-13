// https://leetcode.com/problems/length-of-last-word/description/

#include <iostream>

using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int count = 0;
        int len = s.length() - 1;
        for (int i = len; i >= 0; i--)
        {
            if (s[i] == ' ' && count > 0)
                break;
            else if (s[i] == ' ')
                continue;
            count++;
        }
        return count;
    }
};

int main()
{
    string str = "Hello World";
    Solution s;
    cout << s.lengthOfLastWord(str) << endl;
}