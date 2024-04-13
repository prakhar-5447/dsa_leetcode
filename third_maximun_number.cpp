// https://leetcode.com/problems/third-maximum-number/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        int first, second, third;
        first = second = third = INT_MIN;
        int count = 0;

        int len = nums.size();

        for (int i = 0; i < len; i++)
        {
            if (nums[i] >= third)
            {
                count++;
                int temp = third;
                third = nums[i];

                if (third != INT_MIN && (third == second || third == first))
                {
                    count--;
                    third = temp;
                }

                if (third > second)
                {
                    int temp = third;
                    third = second;
                    second = temp;

                    if (second > first)
                    {
                        int temp = second;
                        second = first;
                        first = temp;
                    }
                }
            }
        }

        if (count >= 3 && third < second)
            return third;
        return first;
    }
};

int main()
{
    Solution s;
    vector<int> result = {3, 2, 1};
    cout << s.thirdMax(result) << endl;
}