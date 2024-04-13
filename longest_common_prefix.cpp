// https://leetcode.com/problems/longest-common-prefix/description/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// class Solution
// {
// public:
//     string longestCommonPrefix(vector<string> &strs)
//     {
//         string valid = strs[0];
//         int i = 1;
//         while (i < strs.size())
//         {
//             int j = 0;
//             string temp = strs[i];
//             int strlen = temp.length();
//             while (j < valid.length() && j < strlen)
//             {
//                 if (temp[j] != valid[j])
//                     break;
//                 j++;
//             }
//             valid = temp.substr(0, j);
//             i++;
//         }

//         return valid;
//     }
// };

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string valid = strs[0];
        string ans = "";
        int i = 1;
        while (i < strs.size())
        {
            int j = 0;
            string temp = strs[i];
            int strlen = temp.length();
            while (j < valid.length() && j < strlen)
            {
                if (temp[j] != valid[j])
                {
                    j++;
                    break;
                }
                ans.push_back(temp[j]);

                j++;
            }
            valid = ans;
            ans = "";
            i++;
        }

        return valid;
    }
};

int main()
{
    vector<string> str = {"ab", "a"};
    Solution s;
    cout << s.longestCommonPrefix(str) << endl;
}