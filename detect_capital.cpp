// https://leetcode.com/problems/detect-capital/description/

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        if (word.length() > 1)
        {
            int high = -1, low = -1;

            if (word[1] >= 65 && word[1] <= 90)
            {
                high = 90;
                low = 65;
            }
            else if (word[1] >= 97 && word[1] <= 122)
            {
                high = 122;
                low = 97;
            }

            if (low == 65)
            {
                if (!(word[0] >= 65 && word[0] <= 90))
                    return false;
            }

            for (int i = 2; i < word.length(); i++)
            {
                if (!(word[i] >= low && word[i] <= high))
                    return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution s;
    cout << s.detectCapitalUse("USA") << endl;
}