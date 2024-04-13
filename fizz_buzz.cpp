// https://leetcode.com/problems/fizz-buzz/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> result;
        int countThree = 1;
        int countFive = 1;

        for (int i = 1; i <= n; i++, countThree++, countFive++)
        {
            countThree %= 3;
            countFive %= 5;
            if (!countThree && !countFive)
                result.push_back("FizzBuzz");
            else if (!countThree)
                result.push_back("Fizz");
            else if (!countFive)
                result.push_back("Buzz");
            else
                result.push_back(to_string(i));
        }

        return result;
    }
};

int main()
{
    Solution s;
    vector<string> ans = s.fizzBuzz(5);
    vector<string>::iterator it;
    for (it = ans.begin(); it != ans.end(); it++)
    {
        cout << *it << " ";
    }
}