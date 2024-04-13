// https://leetcode.com/problems/number-of-segments-in-a-string/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int countSegments(string s)
    {
        int count = 0;
        bool prevSpace = true;
        for (int i = 0; i < s.length(); i++)
        {
            if (!prevSpace && s[i] == ' ')
            {
                count++;
                prevSpace = true;
            }
            else if (s[i] != ' ')
                prevSpace = false;
        }

        if (!prevSpace)
            return count + 1;
        return count;
    }
};

// class Solution
// {
// public:
//     int countSegments(string s)
//     {
//         int count = 0;
//         bool prevSpace = true;
//         for (int i = 0; i < s.length(); i++)
//         {
//             if (prevSpace && s[i] == ' '){

//             }else if(s[i]== ' '){
//               count++;
//               prevSpace = true;
//             }
//             else
//               prevSpace = false;

//         }

//         if(!prevSpace) return count + 1;
//         return count;
//     }
// };

int main()
{
    Solution s;
    cout << s.countSegments("Hello, my name is John") << endl;
}