// https://leetcode.com/problems/valid-palindrome/description/

#include <iostream>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int i = 0;
        int j = s.length() - 1;

        while (j > i)
        {
            if (s[i] >= 48 && s[i] <= 57)
            {
                if (s[j] >= 48 && s[j] <= 57)
                {
                    if (s[i] == s[j])
                    {
                        i++;
                        j--;
                    }
                    else
                        return false;
                }
                else if ((s[j] >= 65 && s[j] <= 90) || (s[j] >= 97 && s[j] <= 122))
                {
                    return false;
                }
                else
                {
                    j--;
                }
            }
            else if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
            {
                if ((s[j] >= 65 && s[j] <= 90) || (s[j] >= 97 && s[j] <= 122))
                {
                    if (s[j] + 32 == s[i] || s[i] + 32 == s[j] || s[i] == s[j])
                    {
                        i++;
                        j--;
                    }
                    else
                        return false;
                }
                else if (s[j] >= 48 && s[j] <= 57)
                {
                    return false;
                }
                else
                {
                    j--;
                }
            }
            else
            {
                i++;
            }
        }

        return true;
    }
};

int main()
{
    string s = "A man, a plan, a canal: Panama";
    Solution sol;

    if (sol.isPalindrome(s))
    {
        cout << "string is palindrome" << endl;
    }
    else
    {
        cout << "string is not palindrome" << endl;
    }
}