// https://leetcode.com/problems/student-attendance-record-i/description/

#include <iostream>

using namespace std;

class Solution
{
public:
    bool checkRecord(string s)
    {
        int countA = 0;
        char prev;
        int countL = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'A')
                countA++;
            else if (s[i] == 'L')
            {
                if (s[i] == prev)
                    countL++;
                else
                    countL = 0;
            }
            prev = s[i];
            if (countA >= 2 || countL >= 2)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout << s.checkRecord("ALLPLLPPP") << endl;
}