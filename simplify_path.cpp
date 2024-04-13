// https://leetcode.com/problems/simplify-path/description/

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        stack<string> s;
        string ans;
        int i, j;

        for (i = 0; i < path.length();)
        {
            if (path[i] != '/')
            {
                string temp;
                for (j = i; j < path.length() && path[j] != '/'; j++)
                    temp.push_back(path[j]);
                i = j;

                if (temp == "..")
                {
                    if (!s.empty())
                        s.pop();
                }
                else if (temp == ".")
                    continue;
                else
                    s.push(temp);
            }
            else
                i++;
        }

        if (s.empty())
            return "/";

        while (!s.empty())
        {
            ans.insert(0, "/" + s.top());
            s.pop();
        }

        return ans;
    }
};

int main()
{
    Solution s;
    string ans = s.simplifyPath("../..ga/b/.f..d/..../e.baaeeh./.a");
    cout << ans << endl;
}