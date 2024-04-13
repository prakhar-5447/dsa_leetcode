// https://leetcode.com/problems/roman-to-integer/description/*

#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string value(int place, int val)
    {
        string temp;
        char c1, c2, c3;

        if (place == 4)
        {
            while (val)
            {
                temp.push_back('M');
                val--;
            }

            return temp;
        }
        else if (place == 1)
        {
            c1 = 'I';
            c2 = 'V';
            c3 = 'X';
        }
        else if (place == 2)
        {

            c1 = 'X';
            c2 = 'L';
            c3 = 'C';
        }
        else
        {
            c1 = 'C';
            c2 = 'D';
            c3 = 'M';
        }

        if (val == 9)
        {
            temp.push_back(c3);
            temp.push_back(c1);
        }
        else if (val == 4)
        {
            temp.push_back(c2);
            temp.push_back(c1);
        }
        else if (val >= 5)
        {
            while (val % 5)
            {
                temp.push_back(c1);
                val--;
            }
            temp.push_back(c2);
        }
        else
        {
            while (val)
            {
                temp.push_back(c1);
                val--;
            }
        }

        return temp;
    }

    string intToRoman(int num)
    {
        string ans = "";
        int place = 1;

        while (num)
        {
            int temp = num % 10;
            ans.append(value(place, temp));
            num /= 10;
            place++;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution s;
    cout << "value is " << s.intToRoman(2345) << endl;
}